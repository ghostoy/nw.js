#include "nw_shortcut_api.h"
#include "base/lazy_instance.h"
#include "base/memory/scoped_ptr.h"
#include "base/values.h"
#include "chrome/browser/extensions/global_shortcut_listener.h"
#include "content/nw/src/api/nw_shortcut.h"
#include "content/nw/src/api/nw_util.h"
#include "extensions/browser/extensions_browser_client.h"
#include "ui/base/accelerators/accelerator.h"
#include "ui/events/event_constants.h"
#include "ui/events/keycodes/dom/keycode_converter.h"
#include "ui/events/keycodes/keyboard_codes.h"
#include "ui/events/keycodes/keyboard_code_conversion.h"

using namespace extensions::nwapi::nw__shortcut;
using namespace content;

namespace extensions {

class NWShortcutObserver : public GlobalShortcutListener::Observer {
public:
  static NWShortcutObserver* GetInstance();

  // ui::GlobalShortcutListener::Observer implementation.
  void OnKeyPressed(const ui::Accelerator& uiAccelerator) override;

};

namespace {

  void DispatchEvent(
      events::HistogramValue histogram_value,
      const std::string& event_name,
      scoped_ptr<base::ListValue> args) {
    DCHECK_CURRENTLY_ON(BrowserThread::UI);
    ExtensionsBrowserClient::Get()->BroadcastEventToRenderers(
                                                              histogram_value, event_name, std::move(args));
  }

  base::LazyInstance<NWShortcutObserver>::Leaky
    g_nw_shortcut_observer_ = LAZY_INSTANCE_INITIALIZER;

} //

// static
NWShortcutObserver* NWShortcutObserver::GetInstance() {
  return g_nw_shortcut_observer_.Pointer();
}

void NWShortcutObserver::OnKeyPressed (const ui::Accelerator& uiAccelerator) {
  std::string accelerator = nw::util::ConvertAcceleratorToString(uiAccelerator);
  scoped_ptr<base::ListValue> args = 
    nwapi::nw__shortcut::OnKeyPressed::Create(accelerator);
  DispatchEvent(
    events::HistogramValue::UNKNOWN, 
    nwapi::nw__shortcut::OnKeyPressed::kEventName,
    std::move(args));
}

bool NwShortcutRegisterAcceleratorFunction::RunNWSync(base::ListValue* response, std::string* error) {
  std::string acceleratorString;
  EXTENSION_FUNCTION_VALIDATE(args_->GetString(0, &acceleratorString));
  ui::Accelerator uiAccelerator = nw::util::ConvertStringToAccelerator(acceleratorString);

  if (!GlobalShortcutListener::GetInstance()->RegisterAccelerator(uiAccelerator, NWShortcutObserver::GetInstance())) {
    response->AppendBoolean(false);
    return true;
  }

  response->AppendBoolean(true);
  return true;
}

bool NwShortcutUnregisterAcceleratorFunction::RunNWSync(base::ListValue* response, std::string* error) {
  std::string acceleratorString;
  EXTENSION_FUNCTION_VALIDATE(args_->GetString(0, &acceleratorString));
  ui::Accelerator uiAccelerator = nw::util::ConvertStringToAccelerator(acceleratorString);

  GlobalShortcutListener::GetInstance()->UnregisterAccelerator(uiAccelerator, NWShortcutObserver::GetInstance());
  response->AppendBoolean(true);
  return true;
}

} // extensions

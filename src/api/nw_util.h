#ifndef CONTENT_NW_UTIL_H
#define CONTENT_NW_UTIL_H

#include "ui/base/accelerators/accelerator.h"
#include "ui/events/keycodes/dom/keycode_converter.h"
#include "ui/events/keycodes/keyboard_codes.h"//for keycode
#include "ui/events/keycodes/keyboard_code_conversion.h"

namespace nw {

  namespace util {

  ui::KeyboardCode GetKeycodeFromText(const std::string& text);
  int GetModifiersFromText(const std::string& text);

  std::string GetTextFromKeycode(const ui::KeyboardCode& code);
  std::string GetTextFromModifiers(const int& modifiers);

  ui::Accelerator ConvertStringToAccelerator(const std::string& text);
  std::string ConvertAcceleratorToString(const ui::Accelerator& accelerator);
  
  } // nw::util

} // nw

#endif // CONTENT_NW_UTIL_H
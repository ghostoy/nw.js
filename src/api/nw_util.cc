#include "content/nw/src/api/nw_util.h"

#include "base/strings/string_split.h"
#include "base/strings/string_util.h"
#include <map>

namespace nw {

namespace util {

namespace {

typedef std::map<std::string,std::string> KeyMap;
/*
{
  {"`"    , "Backquote"},
  {"\\"   , "Backslash"},
  {"["    , "BracketLeft"},
  {"]"    , "BracketRight"},
  {","    , "Comma"},
  {"="    , "Equal"},
  {"-"    , "Minus"},
  {"."    , "Period"},
  {"'"    , "Quote"},
  {";"    , "Semicolon"},
  {"/"    , "Slash"},
  {"\n"   , "Enter"},
  {"\t"   , "Tab"},
  {"UP"   , "ArrowUp"},
  {"DOWN" , "ArrowDown"},
  {"LEFT" , "ArrowLeft"},
  {"RIGHT", "ArrowRight"},
  {"ESC"  , "Escape"},
  {"MEDIANEXTTRACK", "MediaTrackNext"},
  {"MEDIAPREVTRACK", "MediaTrackPrevious"}
};
*/

static KeyMap InitKeyMap() {
  KeyMap result;
  result["`"] = "Backquote";
  result["\\"] = "Backslash";
  result["["] = "BracketLeft";
  result["]"] = "BracketRight";
  result[","] = "Comma";
  result["="] = "Equal";
  result["-"] = "Minus";
  result["."] = "Period";
  result["'"] = "Quote";
  result[";"] = "Semicolon";
  result["/"] = "Slash";
  result["\n"] = "Enter";
  result["\t"] = "Tab";
  result["UP"] = "ArrowUp";
  result["DOWN"] = "ArrowDown";
  result["LEFT"] = "ArrowLeft";
  result["RIGHT"] = "ArrowRight";
  result["ESC"] = "Escape";
  // backward compatible for 0.12.x
  result["MEDIANEXTTRACK"] = "MediaTrackNext";
  result["MEDIAPREVTRACK"] = "MediaTrackPrevious";

  return result;
}

static KeyMap keymap = InitKeyMap();

static const char* KEY_SEPARATORS = "+-";

}; // nw::<anonymous>

ui::KeyboardCode GetKeycodeFromText(const std::string& text){
  ui::KeyboardCode retval = ui::VKEY_UNKNOWN;
  if (text.size() != 0){
    std::string upperText = base::ToUpperASCII(text);
    std::string keyName = text;
    bool found = false;
    if (upperText.size() == 1){
      char key = upperText[0];
      if (key>='0' && key<='9'){//handle digital
        keyName = "Digit" + upperText;
        found = true;
      } else if (key>='A'&&key<='Z'){//handle alphabet
        keyName = "Key" + upperText;
        found = true;
      }
    }

    if (!found) {
      KeyMap::iterator it = keymap.find(upperText);
      if (it != keymap.end()) {
        keyName = it->second;
        found = true;
      }
    }

    // build keyboard code
    ui::DomCode domCode = ui::KeycodeConverter::CodeStringToDomCodeIgnoreCase(keyName.c_str());
    retval = ui::DomCodeToUsLayoutKeyboardCode(domCode);
  }
  return retval;
}

int GetModifiersFromTextArray(const std::vector<std::string>& v, std::vector<std::string>* left) {
  int modifiers_value = ui::EF_NONE;
  std::vector<std::string>::const_iterator it = v.begin();
  for(; it != v.end(); it++) {
    if (base::LowerCaseEqualsASCII(*it, "ctrl")) {
      modifiers_value |= ui::EF_CONTROL_DOWN;
    } else if (base::LowerCaseEqualsASCII(*it, "shift")){
      modifiers_value |= ui::EF_SHIFT_DOWN ;
    } else if (base::LowerCaseEqualsASCII(*it, "alt")){
      modifiers_value |= ui::EF_ALT_DOWN;
    } else if (base::LowerCaseEqualsASCII(*it, "super")
     || base::LowerCaseEqualsASCII(*it, "cmd")
     || base::LowerCaseEqualsASCII(*it, "command")){
      modifiers_value |= ui::EF_COMMAND_DOWN;
    } else if (left) {
      left->push_back(*it);
    }
  }
  return modifiers_value;
}

std::vector<std::string> SplitKey(const std::string& key) {
  return base::SplitString(
       key, KEY_SEPARATORS, base::TRIM_WHITESPACE, base::SPLIT_WANT_NONEMPTY);
}

int GetModifiersFromText(const std::string& text) {
  return GetModifiersFromTextArray(SplitKey(text), nullptr);
}

std::string GetTextFromKeycode(const ui::KeyboardCode& code) {
  ui::DomCode domCode = ui::UsLayoutKeyboardCodeToDomCode(code);
  return ui::KeycodeConverter::DomCodeToCodeString(domCode);
}

std::string GetTextFromModifiers(const int& modifiers) {
  std::vector<std::string> parts;
  if (modifiers & ui::EF_COMMAND_DOWN) {
    parts.push_back("command");
  }
  if (modifiers & ui::EF_CONTROL_DOWN) {
    parts.push_back("ctrl");
  }
  if (modifiers & ui::EF_SHIFT_DOWN) {
    parts.push_back("shift");
  }
  if (modifiers & ui::EF_ALT_DOWN) {
    parts.push_back("alt");
  }
  return base::JoinString(parts, "+");
}

ui::Accelerator ConvertStringToAccelerator(const std::string& text) {
  ui::Accelerator accelerator;
  std::vector<std::string> tokens = SplitKey(text);
  std::vector<std::string> left;
  int modifiers = GetModifiersFromTextArray(tokens, &left);
  if (left.empty()) {
    return ui::Accelerator(ui::VKEY_UNKNOWN, modifiers);
  }
  return ui::Accelerator(GetKeycodeFromText(left[0]), modifiers);
}

std::string ConvertAcceleratorToString(const ui::Accelerator& accelerator) {
  ui::KeyboardCode code = accelerator.key_code();
  int modifiers = accelerator.modifiers();
  std::string modifiersPart = GetTextFromModifiers(modifiers);
  std::string keyPart = GetTextFromKeycode(code);
  if (modifiersPart.empty()) {
    return keyPart;
  }
  return modifiersPart + "+" + keyPart;
}

} // nw::util

} // nw

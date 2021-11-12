#ifndef _HID_KEYBOARD_STATE_UTIL_H
#define _HID_KEYBOARD_STATE_UTIL_H

#include "./hid_keyboard_state.h"
#include "../../KeyboardApi/keyboard_report.h"

namespace hid_keyboard
{
    void dumpHidKeyboardState(HidKeyboardState *hks, char *outBuffer);
    void dumpHidKeyboardReport(keyboard_api::KeyboardReport *keyboardReport, char *outBuffer);

    void copyKeyboardReport(keyboard_api::KeyboardReport *dest, const keyboard_api::KeyboardReport *src);
}
#endif
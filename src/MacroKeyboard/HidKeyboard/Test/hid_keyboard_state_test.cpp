#include <iostream>

#include "hid_keyboard_test.h"

#include "../Inc/hid_keyboard_state.h"
#include "../Inc/hid_keyboard_state_util.h"
#include "../../KeyboardApi/keyboard_report.h"

#include "../Inc/hid_key_codes.h"

using namespace std;
using namespace hid_keyboard;

void sendTestMethod(keyboard_api::KeyboardReport *keyboardReport);

int test::hid_keyboard_state_test()
{
    HidKeyboardState hks = HidKeyboardState(255, sendTestMethod);
    hks.keyDown(HID_KEY_MOD_LSHIFT, 1);
    hks.sendReport();
    hks.keyDown(HID_KEY_A, 0);
    hks.sendReport();
    hks.keyDown(HID_KEY_B, 0);
    hks.sendReport();
    hks.keyDown(HID_KEY_MOD_LCTRL, 1);
    hks.sendReport();

    hks.keyUp(HID_KEY_MOD_LCTRL, 1);
    hks.sendReport();
    hks.keyUp(HID_KEY_A, 0);
    hks.sendReport();
    hks.keyUp(HID_KEY_B, 0);
    hks.sendReport();
    hks.keyUp(HID_KEY_MOD_LSHIFT, 1);
    hks.sendReport();

    return 0;
}

void sendTestMethod(keyboard_api::KeyboardReport *keyboardReport)
{
    char outText[512] = {0};

    dumpHidKeyboardReport(keyboardReport, outText);

    cout << "KR: \t" << outText << endl;
}
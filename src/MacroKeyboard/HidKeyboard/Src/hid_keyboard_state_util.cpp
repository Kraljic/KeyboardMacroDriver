#include "../Inc/hid_keyboard_state_util.h"

#include <string.h>
#include <stdio.h>

namespace hid_keyboard
{
    void dumpHidKeyboardState(HidKeyboardState *hks, char *outBuffer)
    {
        keyboard_api::KeyboardReport keyboardReport = hks->getKeyboardReport();
        dumpHidKeyboardReport(&keyboardReport, outBuffer);
    }

    void dumpHidKeyboardReport(keyboard_api::KeyboardReport *keyboardReport, char *outBuffer)
    {
        uint8_t i;
        char numberText[10] = {0};

        outBuffer[0] = '\0'; // clear buffer

        sprintf(numberText, "0x%02X\t", keyboardReport->modKeys);
        strcat(outBuffer, numberText);

        for (i = 0; i < KEYBOARD_REPORT_KEY_NUM; i++)
        {
            sprintf(numberText, "0x%02X ", keyboardReport->keys[i]);
            strcat(outBuffer, numberText);
        }

        strcat(outBuffer, "\r\n");
    }

    void copyKeyboardReport(keyboard_api::KeyboardReport *dest, const keyboard_api::KeyboardReport *src)
    {
        dest->reportId = src->reportId;
        dest->modKeys = src->modKeys;
        memcpy(dest->keys, src->keys, KEYBOARD_REPORT_KEY_NUM);
    }
}
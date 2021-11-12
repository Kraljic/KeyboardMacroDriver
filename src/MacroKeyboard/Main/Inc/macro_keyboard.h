#ifndef _MACRO_KEYBOARD
#define _MACRO_KEYBOARD

#include <inttypes.h>
#include "macro_keyboard_config.h"
#include "../../KeyboardApi/keyboard_report.h"
#include "../../Macro/Inc/macro_command_handler.h"
#include "../../Macro/Inc/macro_executor.h"

namespace macro_keyboard
{
    class MacroKeyboard
    {
    private:
        static MacroKeyboardConfig *macroKeyboardConfig;

        static uint8_t keyNotHandled;
        static hid_keyboard::HidKeyboardState *inputKeyboardState;
        static macro_api::MacroExecutor *macroExecutor;

        MacroKeyboard();

        static void setKeyNotHandled();
        static void setKeyHandled();

    public:
        static void (*receivePs2Data)(uint8_t);

        static void init(MacroKeyboardConfig *macroKeyboardConfig);
        static void run();
    };
}

#endif
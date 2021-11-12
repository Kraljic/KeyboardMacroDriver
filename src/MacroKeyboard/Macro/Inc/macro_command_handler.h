#ifndef _MACRO_COMMAND_HANDLER_H
#define _MACRO_COMMAND_HANDLER_H

#include <inttypes.h>
#include "macro_command.h"
#include "../../HidKeyboard/Inc/hid_keyboard_state.h"

namespace macro_api
{
    /** It reads macro data from given address and sends commands to output keyboard state object. */
    class MacroCommandHandler
    {
    private:
        hid_keyboard::HidKeyboardState *keyboardState;

        void keyDown(void **data, uint8_t cmd);
        void keyUp(void **data, uint8_t cmd);
        void keyPress(void **data, uint8_t cmd);

        void delayShort(void **data, uint8_t cmd);
        void delayLong(void **data, uint8_t cmd);
        void delayLongLong(void **data, uint8_t cmd);

        void keyStream(void **data, uint8_t cmd);

    public:
        /** Requeres reference of output keyboard to which commands are being sent to. */
        MacroCommandHandler(hid_keyboard::HidKeyboardState *keyboardState);

        /**
         *  Handles command and returns pointer of next command. Returns null pointer if no commands available.
         * 
         * @param data address of macro command
         * @return Address of next instruction or 0 (null pointer) if it comes to end instruction or error ocures.
         */
        void *handleCommand(void *data);
    };

}

#endif
#ifndef _HID_KEYBOARD_STATE_H
#define _HID_KEYBOARD_STATE_H

#include <inttypes.h>
#include "./hid_key.h"
#include "../../KeyboardApi/keyboard_report.h"

namespace hid_keyboard
{
    /** Represents the state of keyboard, it can hold modifier keys and up to 5 normal keys. 
     * It also can have refrence to sendReport method so it can send data to output.
    */
    class HidKeyboardState
    {
    private:
        keyboard_api::KeyboardReport _internalKeyboardState = {0};

        uint8_t _keyDown(uint8_t hidCode);
        uint8_t _keyUp(uint8_t hidCode);
        uint8_t _modDown(uint8_t hidCode);
        uint8_t _modUp(uint8_t hidCode);

        void (*sendProto)(keyboard_api::KeyboardReport *);

    public:
        /** 
         * @param reportId default reportId that will be sent for most of the commands.
         * @param sendMethod refrence to sendReport method that forwards keyboardReport to output pereferals.
        */
        HidKeyboardState(uint8_t reportId, void (*sendMethod)(keyboard_api::KeyboardReport *));

        uint8_t keyDown(uint8_t hidCode, uint8_t modKey);
        uint8_t keyUp(uint8_t hidCode, uint8_t modKey);
        uint8_t handleKey(HidKey hidKey);

        /** Send curent keyboard state to output pereferal.
         * 
         * @return execution status --> 1 if success or 0 if not executed
         */
        uint8_t sendReport();

        /** Get curent keyboard state. */
        keyboard_api::KeyboardReport getKeyboardReport();
    };
}

#endif

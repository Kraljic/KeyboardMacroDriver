#ifndef _ASCII_TO_HID_H
#define _ASCII_TO_HID_H

#include <inttypes.h>
#include <ctype.h>
#include "../../HidKeyboard/Inc/hid_key_codes.h"

namespace transcoders
{
    class AsciiToHidTranscoder
    {
    private:
        static const uint16_t SHIFT = HID_KEY_MOD_LSHIFT << 8;
        AsciiToHidTranscoder();

    public:
        // convert ascii character to USB HID Keyboard scancode.
        // realize that there is no difference between 'A'/'a' or '1'/'!', they have the same scancode.
        // In order to differentiate between these the SHIFT modifier has to be set (see kb_modifier_t).
        // See kb_scancode_t for other scancodes that are not ascii.
        // bit8 will be set if shift needs to be set (for upper case chars or '!' vs '1')
        static uint16_t asciiToHid(char c);
    };

}

#endif
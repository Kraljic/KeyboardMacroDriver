#ifndef _HID_KEY_H
#define _HID_KEY_H

#include <inttypes.h>

namespace hid_keyboard
{
    typedef struct
    {
        uint8_t hidCode;
        uint8_t modKey;
        uint8_t released;

        uint8_t error;
    } HidKey;
} // namespace hid_keyboard

#endif
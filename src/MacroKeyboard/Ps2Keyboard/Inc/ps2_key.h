#ifndef _PS2_KEY_H
#define _PS2_KEY_H

#include <inttypes.h>

namespace ps2_keyboard
{
    typedef struct
    {
        uint8_t ps2Extended;
        uint8_t ps2Special;
        uint8_t ps2Code;
        uint8_t released;

        uint8_t done;
        uint8_t error;
    } Ps2Key;
} // namespace ps2_keyboard

#endif
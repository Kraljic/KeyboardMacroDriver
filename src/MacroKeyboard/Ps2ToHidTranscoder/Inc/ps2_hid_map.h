#ifndef _PS2_HID_MAP_H
#define _PS2_HID_MAP_H

#include <inttypes.h>
#include "../../Ps2Keyboard/Inc/ps2_key.h"
#include "../../HidKeyboard/Inc/hid_key.h"

using namespace ps2_keyboard;
using namespace hid_keyboard;

namespace ps2_to_hid_transcoder
{
    class Ps2HidMap
    {
    private:
        static const uint8_t PS2_HID_MAP_SIZE = (0x83 + 100);     // 0x83 - highest
        static const uint8_t PS2_EXT_HID_MAP_SIZE = (0x7D + 100); // 0x7D - highest

        static uint8_t ps2ToHidLookupMap[PS2_HID_MAP_SIZE];
        static uint8_t ps2ExtToHidLookupMap[PS2_EXT_HID_MAP_SIZE];

        static uint8_t initDone;

    public:
        static void init();

        static uint8_t getKey(uint8_t ps2ScanCode);
        static uint8_t getExtendedKey(uint8_t ps2ScanCode);
    };

}

#endif
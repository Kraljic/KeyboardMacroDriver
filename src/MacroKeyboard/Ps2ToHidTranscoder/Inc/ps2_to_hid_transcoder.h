#ifndef _PS2_TO_HID_TRANSCODER_H
#define _PS2_TO_HID_TRANSCODER_H

#include <inttypes.h>
#include "./ps2_hid_map.h"
#include "../../Ps2Keyboard/Inc/ps2_key.h"
#include "../../HidKeyboard/Inc/hid_key.h"

using namespace ps2_keyboard;
using namespace hid_keyboard;

namespace ps2_to_hid_transcoder
{
    class Ps2ToHidTranscoder
    {
    private:
        static uint8_t translateModKey(uint8_t hidCode);

        Ps2ToHidTranscoder();

    public:
        static void init();

        static HidKey transcode(Ps2Key ps2Key);
    };

}

#endif
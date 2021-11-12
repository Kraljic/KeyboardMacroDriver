#include "../Inc/ps2_to_hid_transcoder.h"

#include "../../HidKeyboard/Inc/hid_key_codes.h"

namespace ps2_to_hid_transcoder
{
    Ps2ToHidTranscoder::Ps2ToHidTranscoder() {}

    void Ps2ToHidTranscoder::init()
    {
        Ps2HidMap::init();
    }

    HidKey Ps2ToHidTranscoder::transcode(Ps2Key ps2Key)
    {
        HidKey hidKey = {0};

        if (ps2Key.error || ps2Key.ps2Special)
        {
            hidKey.error = 1;
            return hidKey;
        }

        uint8_t hidCode = ps2Key.ps2Extended
                              ? Ps2HidMap::getExtendedKey(ps2Key.ps2Code)
                              : Ps2HidMap::getKey(ps2Key.ps2Code);

        uint8_t modKey = translateModKey(hidCode);

        hidKey.hidCode = modKey ? modKey : hidCode;
        hidKey.modKey = modKey ? 1 : 0;
        hidKey.released = ps2Key.released;
        hidKey.error = hidKey.hidCode == 0x00;

        return hidKey;
    }

    uint8_t Ps2ToHidTranscoder::translateModKey(uint8_t hidCode)
    {
        switch (hidCode)
        {
        case HID_KEY_LEFTCTRL:
            return HID_KEY_MOD_LCTRL;
        case HID_KEY_LEFTSHIFT:
            return HID_KEY_MOD_LSHIFT;
        case HID_KEY_LEFTALT:
            return HID_KEY_MOD_LALT;
        case HID_KEY_LEFTMETA:
            return HID_KEY_MOD_LMETA;
        case HID_KEY_RIGHTCTRL:
            return HID_KEY_MOD_RCTRL;
        case HID_KEY_RIGHTSHIFT:
            return HID_KEY_MOD_RSHIFT;
        case HID_KEY_RIGHTALT:
            return HID_KEY_MOD_RALT;
        case HID_KEY_RIGHTMETA:
            return HID_KEY_MOD_RMETA;
        default:
            return 0;
        }
    }
}
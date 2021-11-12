#include "ps2_to_hid_transcoder_test.h"
#include <iostream>

#include "../../Ps2Keyboard/Inc/ps2_key_codes.h"
#include "../Inc/ps2_to_hid_transcoder.h"
#include "../Inc/ps2_hid_map.h"

using namespace std;
using namespace ps2_to_hid_transcoder;

#define PRESS_KEY(key, code, errFlag)         \
    key.ps2Code = (uint8_t)((code)&0xFF);     \
    key.ps2Extended = (uint8_t)((code) >> 8); \
    key.released = 0;                         \
    key.error = (errFlag);

#define RELEASE_KEY(key, code, errFlag)         \
    (key).ps2Code = (uint8_t)((code)&0xFF);     \
    (key).ps2Extended = (uint8_t)((code) >> 8); \
    (key).released = 1;                         \
    (key).error = errFlag;

void printHidKey(HidKey hidKey);

int test::ps2_to_hid_transcoder_test()
{
    Ps2Key ps2Key = {0};
    HidKey hidKey = {0};

    // Test KEY PRESS A
    PRESS_KEY(ps2Key, PS2_KEY_A, 0)
    hidKey = Ps2ToHidTranscoder::transcode(ps2Key);
    printHidKey(hidKey);

    RELEASE_KEY(ps2Key, PS2_KEY_A, 0)
    hidKey = Ps2ToHidTranscoder::transcode(ps2Key);
    printHidKey(hidKey);

    // Test KEY PRESS RIGHT CONTROL
    PRESS_KEY(ps2Key, PS2_KEY_MOD_RCTRL, 0)
    hidKey = Ps2ToHidTranscoder::transcode(ps2Key);
    printHidKey(hidKey);

    RELEASE_KEY(ps2Key, PS2_KEY_MOD_RCTRL, 0)
    hidKey = Ps2ToHidTranscoder::transcode(ps2Key);
    printHidKey(hidKey);

    // Test KEY PRESS RIGHT ARROW (extended key)
    PRESS_KEY(ps2Key, PS2_KEY_RIGHT, 0)
    hidKey = Ps2ToHidTranscoder::transcode(ps2Key);
    printHidKey(hidKey);

    RELEASE_KEY(ps2Key, PS2_KEY_RIGHT, 0)
    hidKey = Ps2ToHidTranscoder::transcode(ps2Key);
    printHidKey(hidKey);

    // Test key error - should produce error
    PRESS_KEY(ps2Key, PS2_KEY_RIGHT, 1)
    hidKey = Ps2ToHidTranscoder::transcode(ps2Key);
    printHidKey(hidKey);

    RELEASE_KEY(ps2Key, PS2_KEY_RIGHT, 1)
    hidKey = Ps2ToHidTranscoder::transcode(ps2Key);
    printHidKey(hidKey);

    // Test fake key - should produce error
    PRESS_KEY(ps2Key, PS2_KEY_FAKE_SHIFT, 0)
    hidKey = Ps2ToHidTranscoder::transcode(ps2Key);
    printHidKey(hidKey);

    RELEASE_KEY(ps2Key, PS2_KEY_FAKE_SHIFT, 0)
    hidKey = Ps2ToHidTranscoder::transcode(ps2Key);
    printHidKey(hidKey);

    return 0;
}

void printHidKey(HidKey hidKey)
{
    cout << "Code: " << (uint32_t *)(uint32_t)hidKey.hidCode
         << " | Mod: " << (uint16_t)hidKey.modKey
         << " | State: " << (uint16_t)!hidKey.released
         << " | Error: " << (uint16_t)hidKey.error << endl;
}
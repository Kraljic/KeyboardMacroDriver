#include "../Inc/ps2_hid_map.h"

#include "../../Ps2Keyboard/Inc/ps2_key_codes.h"
#include "../../HidKeyboard/Inc/hid_key_codes.h"

#define PS2_EXT_CODE(fullCode) ((uint8_t)(fullCode)&0xFF)

namespace ps2_to_hid_transcoder
{
    uint8_t Ps2HidMap::ps2ToHidLookupMap[Ps2HidMap::PS2_HID_MAP_SIZE] = {0};
    uint8_t Ps2HidMap::ps2ExtToHidLookupMap[Ps2HidMap::PS2_EXT_HID_MAP_SIZE] = {0};
    uint8_t Ps2HidMap::initDone = 0;

    uint8_t Ps2HidMap::getKey(uint8_t ps2ScanCode)
    {
        if (ps2ScanCode >= PS2_HID_MAP_SIZE)
            return 0;

        return ps2ToHidLookupMap[ps2ScanCode];
    }
    uint8_t Ps2HidMap::getExtendedKey(uint8_t ps2ScanCode)
    {
        if (ps2ScanCode >= PS2_EXT_HID_MAP_SIZE)
            return 0;

        return ps2ExtToHidLookupMap[ps2ScanCode];
    }

    void Ps2HidMap::init()
    {
        if (initDone)
            return;

        /// PS2 KEY CODES init
        ps2ToHidLookupMap[PS2_KEY_MOD_LCTRL] = HID_KEY_LEFTCTRL;
        ps2ToHidLookupMap[PS2_KEY_MOD_LSHIFT] = HID_KEY_LEFTSHIFT;
        ps2ToHidLookupMap[PS2_KEY_MOD_LALT] = HID_KEY_LEFTALT;
        ps2ToHidLookupMap[PS2_KEY_MOD_RSHIFT] = HID_KEY_RIGHTSHIFT;

        ps2ToHidLookupMap[PS2_KEY_A] = HID_KEY_A;
        ps2ToHidLookupMap[PS2_KEY_B] = HID_KEY_B;
        ps2ToHidLookupMap[PS2_KEY_C] = HID_KEY_C;
        ps2ToHidLookupMap[PS2_KEY_D] = HID_KEY_D;
        ps2ToHidLookupMap[PS2_KEY_E] = HID_KEY_E;
        ps2ToHidLookupMap[PS2_KEY_F] = HID_KEY_F;
        ps2ToHidLookupMap[PS2_KEY_G] = HID_KEY_G;
        ps2ToHidLookupMap[PS2_KEY_H] = HID_KEY_H;
        ps2ToHidLookupMap[PS2_KEY_I] = HID_KEY_I;
        ps2ToHidLookupMap[PS2_KEY_J] = HID_KEY_J;
        ps2ToHidLookupMap[PS2_KEY_K] = HID_KEY_K;
        ps2ToHidLookupMap[PS2_KEY_L] = HID_KEY_L;
        ps2ToHidLookupMap[PS2_KEY_M] = HID_KEY_M;
        ps2ToHidLookupMap[PS2_KEY_N] = HID_KEY_N;
        ps2ToHidLookupMap[PS2_KEY_O] = HID_KEY_O;
        ps2ToHidLookupMap[PS2_KEY_P] = HID_KEY_P;
        ps2ToHidLookupMap[PS2_KEY_Q] = HID_KEY_Q;
        ps2ToHidLookupMap[PS2_KEY_R] = HID_KEY_R;
        ps2ToHidLookupMap[PS2_KEY_S] = HID_KEY_S;
        ps2ToHidLookupMap[PS2_KEY_T] = HID_KEY_T;
        ps2ToHidLookupMap[PS2_KEY_U] = HID_KEY_U;
        ps2ToHidLookupMap[PS2_KEY_V] = HID_KEY_V;
        ps2ToHidLookupMap[PS2_KEY_W] = HID_KEY_W;
        ps2ToHidLookupMap[PS2_KEY_X] = HID_KEY_X;
        ps2ToHidLookupMap[PS2_KEY_Y] = HID_KEY_Y;
        ps2ToHidLookupMap[PS2_KEY_Z] = HID_KEY_Z;

        ps2ToHidLookupMap[PS2_KEY_1] = HID_KEY_1;
        ps2ToHidLookupMap[PS2_KEY_2] = HID_KEY_2;
        ps2ToHidLookupMap[PS2_KEY_3] = HID_KEY_3;
        ps2ToHidLookupMap[PS2_KEY_4] = HID_KEY_4;
        ps2ToHidLookupMap[PS2_KEY_6] = HID_KEY_6;
        ps2ToHidLookupMap[PS2_KEY_6] = HID_KEY_6;
        ps2ToHidLookupMap[PS2_KEY_7] = HID_KEY_7;
        ps2ToHidLookupMap[PS2_KEY_8] = HID_KEY_8;
        ps2ToHidLookupMap[PS2_KEY_9] = HID_KEY_9;
        ps2ToHidLookupMap[PS2_KEY_0] = HID_KEY_0;

        ps2ToHidLookupMap[PS2_KEY_ENTER] = HID_KEY_ENTER;
        ps2ToHidLookupMap[PS2_KEY_ESC] = HID_KEY_ESC;
        ps2ToHidLookupMap[PS2_KEY_BACKSPACE] = HID_KEY_BACKSPACE;
        ps2ToHidLookupMap[PS2_KEY_TAB] = HID_KEY_TAB;
        ps2ToHidLookupMap[PS2_KEY_SPACE] = HID_KEY_SPACE;
        ps2ToHidLookupMap[PS2_KEY_MINUS] = HID_KEY_MINUS;
        ps2ToHidLookupMap[PS2_KEY_EQUAL] = HID_KEY_EQUAL;
        ps2ToHidLookupMap[PS2_KEY_LEFTBRACE] = HID_KEY_LEFTBRACE;
        ps2ToHidLookupMap[PS2_KEY_RIGHTBRACE] = HID_KEY_RIGHTBRACE;
        ps2ToHidLookupMap[PS2_KEY_BACKSLASH] = HID_KEY_BACKSLASH;
        ps2ToHidLookupMap[PS2_KEY_LESSTHAN] = HID_KEY_HASHTILDE;
        ps2ToHidLookupMap[PS2_KEY_SEMICOLON] = HID_KEY_SEMICOLON;
        ps2ToHidLookupMap[PS2_KEY_APOSTROPHE] = HID_KEY_APOSTROPHE;
        ps2ToHidLookupMap[PS2_KEY_GRAVE] = HID_KEY_GRAVE;
        ps2ToHidLookupMap[PS2_KEY_COMMA] = HID_KEY_COMMA;
        ps2ToHidLookupMap[PS2_KEY_DOT] = HID_KEY_DOT;
        ps2ToHidLookupMap[PS2_KEY_SLASH] = HID_KEY_SLASH;
        ps2ToHidLookupMap[PS2_KEY_CAPSLOCK] = HID_KEY_CAPSLOCK;

        ps2ToHidLookupMap[PS2_KEY_F1] = HID_KEY_F1;
        ps2ToHidLookupMap[PS2_KEY_F2] = HID_KEY_F2;
        ps2ToHidLookupMap[PS2_KEY_F3] = HID_KEY_F3;
        ps2ToHidLookupMap[PS2_KEY_F4] = HID_KEY_F4;
        ps2ToHidLookupMap[PS2_KEY_F5] = HID_KEY_F5;
        ps2ToHidLookupMap[PS2_KEY_F6] = HID_KEY_F6;
        ps2ToHidLookupMap[PS2_KEY_F7] = HID_KEY_F7;
        ps2ToHidLookupMap[PS2_KEY_F8] = HID_KEY_F8;
        ps2ToHidLookupMap[PS2_KEY_F9] = HID_KEY_F9;
        ps2ToHidLookupMap[PS2_KEY_F10] = HID_KEY_F10;
        ps2ToHidLookupMap[PS2_KEY_F11] = HID_KEY_F11;
        ps2ToHidLookupMap[PS2_KEY_F12] = HID_KEY_F12;

        ps2ToHidLookupMap[PS2_KEY_NUMLOCK] = HID_KEY_NUMLOCK;
        ps2ToHidLookupMap[PS2_KEY_KPASTERISK] = HID_KEY_KPASTERISK;
        ps2ToHidLookupMap[PS2_KEY_KPMINUS] = HID_KEY_KPMINUS;
        ps2ToHidLookupMap[PS2_KEY_KPPLUS] = HID_KEY_KPPLUS;
        ps2ToHidLookupMap[PS2_KEY_KPDOT] = HID_KEY_KPDOT;
        ps2ToHidLookupMap[PS2_KEY_KP1] = HID_KEY_KP1;
        ps2ToHidLookupMap[PS2_KEY_KP2] = HID_KEY_KP2;
        ps2ToHidLookupMap[PS2_KEY_KP3] = HID_KEY_KP3;
        ps2ToHidLookupMap[PS2_KEY_KP4] = HID_KEY_KP4;
        ps2ToHidLookupMap[PS2_KEY_KP5] = HID_KEY_KP5;
        ps2ToHidLookupMap[PS2_KEY_KP6] = HID_KEY_KP6;
        ps2ToHidLookupMap[PS2_KEY_KP7] = HID_KEY_KP7;
        ps2ToHidLookupMap[PS2_KEY_KP8] = HID_KEY_KP8;
        ps2ToHidLookupMap[PS2_KEY_KP9] = HID_KEY_KP9;
        ps2ToHidLookupMap[PS2_KEY_KP0] = HID_KEY_KP0;

        /// Extended PS2 KEY CODES init
        ps2ExtToHidLookupMap[PS2_EXT_CODE(PS2_KEY_MOD_LMETA)] = HID_KEY_LEFTMETA;
        ps2ExtToHidLookupMap[PS2_EXT_CODE(PS2_KEY_MOD_RCTRL)] = HID_KEY_RIGHTCTRL;
        ps2ExtToHidLookupMap[PS2_EXT_CODE(PS2_KEY_MOD_RALT)] = HID_KEY_RIGHTALT;
        ps2ExtToHidLookupMap[PS2_EXT_CODE(PS2_KEY_MOD_RMETA)] = HID_KEY_RIGHTMETA;

        ps2ExtToHidLookupMap[PS2_EXT_CODE(PS2_KEY_SYSRQ)] = HID_KEY_SYSRQ;
        ps2ExtToHidLookupMap[PS2_EXT_CODE(PS2_KEY_SCROLLLOCK)] = HID_KEY_SCROLLLOCK;

        ps2ToHidLookupMap[PS2_EXT_CODE(PS2_KEY_MENU)] = HID_KEY_PROPS;

        ps2ExtToHidLookupMap[PS2_EXT_CODE(PS2_KEY_INSERT)] = HID_KEY_INSERT;
        ps2ExtToHidLookupMap[PS2_EXT_CODE(PS2_KEY_HOME)] = HID_KEY_HOME;
        ps2ExtToHidLookupMap[PS2_EXT_CODE(PS2_KEY_PAGEUP)] = HID_KEY_PAGEUP;
        ps2ExtToHidLookupMap[PS2_EXT_CODE(PS2_KEY_DELETE)] = HID_KEY_DELETE;
        ps2ExtToHidLookupMap[PS2_EXT_CODE(PS2_KEY_END)] = HID_KEY_END;
        ps2ExtToHidLookupMap[PS2_EXT_CODE(PS2_KEY_PAGEDOWN)] = HID_KEY_PAGEDOWN;
        ps2ExtToHidLookupMap[PS2_EXT_CODE(PS2_KEY_RIGHT)] = HID_KEY_RIGHT;
        ps2ExtToHidLookupMap[PS2_EXT_CODE(PS2_KEY_LEFT)] = HID_KEY_LEFT;
        ps2ExtToHidLookupMap[PS2_EXT_CODE(PS2_KEY_DOWN)] = HID_KEY_DOWN;
        ps2ExtToHidLookupMap[PS2_EXT_CODE(PS2_KEY_UP)] = HID_KEY_UP;

        ps2ExtToHidLookupMap[PS2_EXT_CODE(PS2_KEY_KPSLASH)] = HID_KEY_KPSLASH;
        ps2ExtToHidLookupMap[PS2_EXT_CODE(PS2_KEY_KPENTER)] = HID_KEY_KPENTER;

        initDone = 1;
    }
}
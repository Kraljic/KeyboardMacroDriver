#include "../Inc/hid_keyboard_state.h"

#include "../Inc/hid_keyboard_state_util.h"

namespace hid_keyboard
{
    HidKeyboardState::HidKeyboardState(uint8_t reportId, void (*sendMethod)(keyboard_api::KeyboardReport *))
    {
        this->_internalKeyboardState.reportId = reportId;
        this->sendProto = sendMethod;
    }

    uint8_t HidKeyboardState::keyDown(uint8_t hidCode, uint8_t modKey)
    {
        if (modKey)
            return _modDown(hidCode);
        else
            return _keyDown(hidCode);
    }

    uint8_t HidKeyboardState::keyUp(uint8_t hidCode, uint8_t modKey)
    {
        if (modKey)
            return _modUp(hidCode);
        else
            return _keyUp(hidCode);
    }

    uint8_t HidKeyboardState::handleKey(HidKey hidKey)
    {
        if (hidKey.error)
            return hidKey.error;

        if (hidKey.released)
            return keyUp(hidKey.hidCode, hidKey.modKey);
        else
            return keyDown(hidKey.hidCode, hidKey.modKey);
    }

    uint8_t HidKeyboardState::sendReport()
    {
        if (!this->sendProto)
            return 1;

        keyboard_api::KeyboardReport kr = this->getKeyboardReport();
        this->sendProto(&kr);

        return 0;
    }

    keyboard_api::KeyboardReport HidKeyboardState::getKeyboardReport()
    {
        return this->_internalKeyboardState;
    }

    uint8_t HidKeyboardState::_keyDown(uint8_t hidCode)
    {
        // check if key is already pressed, if not add it to end (check if buffer is full)
        uint8_t i;

        for (i = 0; i < KEYBOARD_REPORT_KEY_NUM; i++)
        {
            if (_internalKeyboardState.keys[i] == hidCode)
            {
                return 0; // OK, Key already pressed
            }
            else if (_internalKeyboardState.keys[i] == 0x00)
            {
                _internalKeyboardState.keys[i] = hidCode;
                return 0; // OK
            }
        }

        return 1; // Buffer full
    }

    uint8_t HidKeyboardState::_keyUp(uint8_t hidCode)
    {
        // check if key is in buffer, remove it from buffer, shif everthing from right to left to fill the gap
        uint8_t i;

        // remove key
        for (i = 0; i < KEYBOARD_REPORT_KEY_NUM; i++)
        {
            if (_internalKeyboardState.keys[i] == hidCode)
            {
                _internalKeyboardState.keys[i] = 0;
                break;
            }
        }

        // shift remaining keys to left
        for (i = 0; i < KEYBOARD_REPORT_KEY_NUM - 1; i++)
        {
            if (_internalKeyboardState.keys[i] == 0)
            {
                _internalKeyboardState.keys[i] = _internalKeyboardState.keys[i + 1];
                _internalKeyboardState.keys[i + 1] = 0;
            }
        }

        return 0;
    }

    uint8_t HidKeyboardState::_modDown(uint8_t hidCode)
    {
        _internalKeyboardState.modKeys |= hidCode;
        return 0;
    }

    uint8_t HidKeyboardState::_modUp(uint8_t hidCode)
    {
        _internalKeyboardState.modKeys &= ~hidCode;
        return 0;
    }
}

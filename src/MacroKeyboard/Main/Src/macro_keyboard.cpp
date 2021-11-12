#include "../Inc/macro_keyboard.h"
#include "../../Ps2Keyboard/Inc/ps2_key.h"
#include "../../Ps2Keyboard/Inc/ps2_keyboard_reader.h"
#include "../../Ps2ToHidTranscoder/Inc/ps2_to_hid_transcoder.h"
#include "../../HidKeyboard/Inc/hid_keyboard_state.h"
#include "../../Macro/Inc/macro_util.h"

using namespace ps2_keyboard;
using namespace ps2_to_hid_transcoder;
using namespace macro_api;
using namespace hid_keyboard;

namespace macro_keyboard
{
    MacroKeyboardConfig *MacroKeyboard::macroKeyboardConfig = 0;
    void (*MacroKeyboard::receivePs2Data)(uint8_t) = 0;
    uint8_t MacroKeyboard::keyNotHandled = 0;
    HidKeyboardState *MacroKeyboard::inputKeyboardState = 0;
    MacroExecutor *MacroKeyboard::macroExecutor = 0;

    MacroKeyboard::MacroKeyboard() {}

    void MacroKeyboard::setKeyNotHandled()
    {
        MacroKeyboard::keyNotHandled = 1;
    }
    void MacroKeyboard::setKeyHandled()
    {
        MacroKeyboard::keyNotHandled = 0;
    }

    void MacroKeyboard::init(MacroKeyboardConfig *macroKeyboardConfig)
    {
        // Save macro keyboard config
        MacroKeyboard::macroKeyboardConfig = macroKeyboardConfig;

        // Register receive callback
        MacroKeyboard::receivePs2Data = &Ps2KeyboardReader::receivePs2Date;

        // Register Ps2InputKeyboard state
        MacroKeyboard::inputKeyboardState = new HidKeyboardState(255, 0);

        // Create MacroExecutor for executing macros
        static HidKeyboardState *macroOutKeyboardState = new HidKeyboardState(macroKeyboardConfig->reportId, macroKeyboardConfig->sendReportMethod);
        static MacroCommandHandler *macroCommandHandler = new MacroCommandHandler(macroOutKeyboardState);
        MacroKeyboard::macroExecutor = new MacroExecutor(macroKeyboardConfig->macroDataAddress, macroCommandHandler);
    }

    void MacroKeyboard::run()
    {
        Ps2Key ps2Key;
        HidKey hidKey;
        uint32_t macroTriggerCode;
        uint8_t macroExecutinStatus;

        while (1)
        {
            if (Ps2KeyboardReader::keyAvailable())
            {
                // Read key from PS2 keyboard
                ps2Key = Ps2KeyboardReader::getNextKey();
                if (ps2Key.error)
                    continue;

                // Translate ps2 key to hid key
                hidKey = Ps2ToHidTranscoder::transcode(ps2Key);

                // Check state of the new key, depends for how to handle macro
                if (hidKey.released && keyNotHandled)
                {
                    // Key up event, get trigger code from input keyboard and try find macro
                    macroTriggerCode = MacroUtil::getMacroTriggerCode(MacroKeyboard::inputKeyboardState->getKeyboardReport());

                    macroExecutinStatus = MacroKeyboard::macroExecutor->execute(macroTriggerCode);
                    keyNotHandled = macroExecutinStatus != MacroExecutor::EXECUTED;
                }
                else if (!hidKey.released)
                {
                    // Key down event, register that we gonna need to handle macro
                    keyNotHandled = 1;
                }

                // Register key
                MacroKeyboard::inputKeyboardState->handleKey(hidKey);
            }
        }
    }
}
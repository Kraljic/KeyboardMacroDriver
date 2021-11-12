#include "main_test.h"

#include <iostream>
#include <string.h>

#include "../../_TestUtil/_test_util.h"

#include "../Inc/macro_keyboard.h"
#include "../Inc/macro_keyboard_config.h"
#include "../../Macro/Inc/macro_meta_info.h"
#include "../../Macro/Inc/macro_header.h"
#include "../../Macro/Inc/macro_util.h"
#include "../../HidKeyboard/Inc/hid_key_codes.h"
#include "../../HidKeyboard/Inc/hid_keyboard_state_util.h"
#include "../../Ps2Keyboard/Inc/ps2_key_codes.h"

using namespace std;
using namespace macro_keyboard;
using namespace macro_api;
using namespace keyboard_api;
using namespace hid_keyboard;

void main_keyboard_test_init_memory(void *memory);
void main_keyboard_test_send_keys();
void main_keyboard_test_send_kr(KeyboardReport *kr);
void main_keyboard_test_delay(uint32_t delay);

int test::main_keyboard_test()
{
    void *memory = calloc(1000, sizeof(uint8_t));
    main_keyboard_test_init_memory(memory);

    MacroKeyboardConfig macroKeyboardConfig = {0};
    macroKeyboardConfig.macroDataAddress = memory;
    macroKeyboardConfig.sendReportMethod = &main_keyboard_test_send_kr;
    macroKeyboardConfig.delayMethod = &main_keyboard_test_delay;

    MacroKeyboard::init(&macroKeyboardConfig);
    main_keyboard_test_send_keys();
    MacroKeyboard::run();

    free(memory);
    return 0;
}

void main_keyboard_test_send_kr(KeyboardReport *kr)
{
    // todo: dump
    char outBuffer[512] = {0};
    dumpHidKeyboardReport(kr, outBuffer);
    cout << outBuffer;
}
void main_keyboard_test_delay(uint32_t delay)
{
    cout << "Delay: " << delay << endl
         << endl;
}

void main_keyboard_test_send_keys()
{
    // Execute first macro
    MacroKeyboard::receivePs2Data(PS2_KEY_MOD_LSHIFT);
    MacroKeyboard::receivePs2Data(PS2_KEY_A);
    MacroKeyboard::receivePs2Data(PS2_KEY_REALESED);
    MacroKeyboard::receivePs2Data(PS2_KEY_A);
    MacroKeyboard::receivePs2Data(PS2_KEY_REALESED);
    MacroKeyboard::receivePs2Data(PS2_KEY_MOD_LSHIFT);

    // Execute second macro
    MacroKeyboard::receivePs2Data(PS2_KEY_1);
    MacroKeyboard::receivePs2Data(PS2_KEY_REALESED);
    MacroKeyboard::receivePs2Data(PS2_KEY_1);
}

/** 
 * Inits two macros:
 * @param 1st SHIFT + KEY_A
 * @param 2nd KEY_1
 * 
 * */
void main_keyboard_test_init_memory(void *memory)
{
    MacroMetaInfo *metaInfo = (MacroMetaInfo *)memory;
    MacroHeader *firstMacro = (MacroHeader *)(metaInfo + 1);
    MacroHeader *secondMacro = (MacroHeader *)(firstMacro + 1);
    void *macroData = secondMacro + 1;

    // init meta info
    metaInfo->numberOfMacros = 2;
    metaInfo->macroHeadersRelativeStartAddress = (uint32_t)firstMacro - (uint32_t)memory;
    metaInfo->macroDataRelativeStartAddress = (uint32_t)macroData - (uint32_t)memory;

    // -------- FIRST ---------
    // init first macro
    KeyboardReport kr_first = {0};
    kr_first.modKeys = HID_KEY_MOD_LSHIFT;
    kr_first.keys[0] = HID_KEY_A;
    firstMacro->macroTriggerCode = MacroUtil::getMacroTriggerCode(kr_first); // todo: Edit
    firstMacro->macroBeginRelativeAddress = metaInfo->macroDataRelativeStartAddress;

    // init first macro - first command
    void *firstMacroData = macroData;
    uint8_t *firstMacroData_cmd1 = (uint8_t *)firstMacroData;
    uint8_t *firstMacroData_cmd1_delay = (uint8_t *)(firstMacroData_cmd1 + 1);
    uint16_t *firstMacroData_cmd1_size = (uint16_t *)(firstMacroData_cmd1_delay + 1);
    char *firstMacroData_cmd1_payload = (char *)(firstMacroData_cmd1_size + 1);

    *firstMacroData_cmd1 = CMD_KEY_STREAM;
    *firstMacroData_cmd1_delay = 5;
    *firstMacroData_cmd1_size = 4;
    strncpy(firstMacroData_cmd1_payload, "Test", 4);

    // init first macro - second command
    uint8_t *firstMacroData_cmd2 = (uint8_t *)(firstMacroData_cmd1_payload + 4);
    uint8_t *firstMacroData_cmd2_payload = (uint8_t *)(firstMacroData_cmd2 + 1);

    *firstMacroData_cmd2 = (CMD_KEY_PRESS << 4) | 1;
    *firstMacroData_cmd2_payload = HID_KEY_A;

    // init first macro - end command
    uint8_t *firstMacroData_cmd3 = (uint8_t *)(firstMacroData_cmd2_payload + 1);
    *firstMacroData_cmd3 = CMD_END;

    // -------- SECOND ---------
    // init second macro
    KeyboardReport kr_second = {0};
    kr_second.keys[0] = HID_KEY_1;
    secondMacro->macroTriggerCode = MacroUtil::getMacroTriggerCode(kr_second); // todo: Edit
    secondMacro->macroBeginRelativeAddress = metaInfo->macroDataRelativeStartAddress + 100;
    void *secondMacroData = (void *)((uint8_t *)macroData + 100);

    // todo: fill second macro data
    uint8_t *secondMacroData_cmd1 = (uint8_t *)secondMacroData;
    uint8_t *secondMacroData_cmd1_delay = (uint8_t *)(secondMacroData_cmd1 + 1);
    uint16_t *secondMacroData_cmd1_size = (uint16_t *)(secondMacroData_cmd1_delay + 1);
    char *secondMacroData_cmd1_payload = (char *)(secondMacroData_cmd1_size + 1);

    *secondMacroData_cmd1 = CMD_KEY_STREAM;
    *secondMacroData_cmd1_delay = 10;
    *secondMacroData_cmd1_size = 12;
    strncpy(secondMacroData_cmd1_payload, "Hello world!", 12);

    // init second macro - end command
    uint8_t *secondMacroData_cmd2 = (uint8_t *)(secondMacroData_cmd1_payload + 12);
    *secondMacroData_cmd2 = CMD_END;

    // get total macro size
    metaInfo->totalSize = 250; // todo:
}

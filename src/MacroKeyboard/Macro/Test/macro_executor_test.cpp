#include "macro_test.h"
#include "../../_TestUtil/_test_util.h"
#include "../Inc/macro_meta_info.h"
#include "../Inc/macro_header.h"
#include "../Inc/macro_executor.h"
#include "../../HidKeyboard/Inc/hid_keyboard_state.h"
#include "../../HidKeyboard/Inc/hid_key_codes.h"

#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;
using namespace macro_api;
using namespace hid_keyboard;
using namespace keyboard_api;

void init(void *memory)
{
    MacroMetaInfo *metaInfo = (MacroMetaInfo *)memory;
    MacroHeader *firstMacro = (MacroHeader *)(metaInfo + 1);
    MacroHeader *secondMacro = (MacroHeader *)(firstMacro + 1);
    void *macroData = secondMacro + 1;

    // init meta info
    metaInfo->numberOfMacros = 2;
    metaInfo->macroHeadersRelativeStartAddress = (uint32_t)firstMacro - (uint32_t)memory;
    metaInfo->macroDataRelativeStartAddress = (uint32_t)macroData - (uint32_t)memory;

    // init first macro
    firstMacro->macroTriggerCode = 1;
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

    // init second macro
    secondMacro->macroTriggerCode = 2;
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

    // init first macro - end command
    uint8_t *secondMacroData_cmd2 = (uint8_t *)(secondMacroData_cmd1_payload + 12);
    *secondMacroData_cmd2 = CMD_END;

    // get total macro size
    metaInfo->totalSize = 250; // todo:
}

/* ignore */
void macro_executor_test_send(KeyboardReport *keyboardReport) {}

int test::macro_executor_test()
{
    void *memory = calloc(1000, sizeof(uint8_t));
    init(memory);

    HidKeyboardState ks = HidKeyboardState(99, &macro_executor_test_send);
    MacroCommandHandler handler = MacroCommandHandler(&ks);
    MacroExecutor executor = MacroExecutor(memory, &handler);
    uint8_t status;

    status = executor.execute(1);
    ASSERT_EQUALS(MacroExecutor::EXECUTED, status, "Macro 1 was not executed!");

    status = executor.execute(2);
    ASSERT_EQUALS(MacroExecutor::EXECUTED, status, "Macro 2 was not executed!");

    status = executor.execute(99);
    ASSERT_EQUALS(MacroExecutor::NOT_EXECUTED, status, "Executor returned executed but macro 99 should not exist!");

    free(memory);
    return 0;
}

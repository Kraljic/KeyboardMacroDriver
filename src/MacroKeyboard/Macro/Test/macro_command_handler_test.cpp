#include "macro_test.h"
#include <iostream>
#include <stdlib.h>
#include <string.h>

#include "../../_TestUtil/_test_util.h"

#include "../Inc/macro_command_handler.h"
#include "../../HidKeyboard/Inc/hid_keyboard_state.h"
#include "../../HidKeyboard/Inc/hid_keyboard_state_util.h"
#include "../../HidKeyboard/Inc/hid_key_codes.h"
#include "../../Timer/Inc/delay_util.h"

using namespace std;
using namespace macro_api;
using namespace hid_keyboard;
using namespace delay_util;

void send(keyboard_api::KeyboardReport *);
void testMacroCommandHandlerDelay(uint32_t delay);

#define CMD(cmd) ((cmd) << 4)
#define PRESS_TWO_KEYS_CMD (CMD(CMD_KEY_PRESS) | CMD_MOD_KEY_MASK | 0x02) // Press two keys (first byte are mod keys)

uint8_t buffer[] = {
    CMD_KEY_STREAM,                                                  // KeyStream command
    5,                                                               // delay 5 ticks
    13, 0x00,                                                        // 13 znakova
    'J', 'a', ' ', 's', 'a', 'm', ' ', 'm', 'a', 'r', 'k', 'o', '!', // KeyStream

    PRESS_TWO_KEYS_CMD, // Test Key press, Key down & Key up commands all in one
    HID_KEY_MOD_LSHIFT,
    HID_KEY_M,

    CMD(CMD_DELAY_LONG_LONG), // 512 * 10 ms = 5120 ms
    0, 2, 0, 0,

    CMD(CMD_DELAY_LONG), // 50 * 100 ms = 5000 ms
    50,

    CMD(CMD_DELAY_SHORT), // 18 * 10 ms = 180 ms
    18,

    CMD_END, // Test end cmd

    CMD(CMD_DELAY_SHORT), // This should not happen!
    13,

    0};

#define TEST_NUM_OF_SEND_METHOD_CALLS (26 + 2)
#define TEST_TOTAL_DELAY (26 * 50 + 2 * 10 + 5120 + 5000 + 180)

uint8_t commandAddressIndexes[] = {17, 20, 25, 27, 29};
int testNumOfSendMethodCalls = 0;
int testTotalDelay = 0;

int test::macro_command_handler_test()
{
    Delay::init(&testMacroCommandHandlerDelay);
    HidKeyboardState ks = HidKeyboardState(99, send);
    MacroCommandHandler handler = MacroCommandHandler(&ks);

    // cout << "Started" << endl;
    void *cmdPtr = buffer;
    // cout << "Next cmd.. " << (uint32_t *)cmdPtr << endl;
    int commandId = 0;
    while ((cmdPtr = handler.handleCommand(cmdPtr)))
    {
        // cout << "Next cmd.. " << (uint32_t *)cmdPtr << "\t" << (uint8_t *)cmdPtr - (uint8_t *)buffer << endl;
        int expected = commandAddressIndexes[commandId];
        int returned = (uint8_t *)cmdPtr - (uint8_t *)buffer;

        ASSERT_EQUALS(expected, returned, "Command address index is incorect at id: " << commandId)

        commandId++;
    }
    // cout << "Finished" << endl;

    ASSERT_EQUALS(TEST_NUM_OF_SEND_METHOD_CALLS, testNumOfSendMethodCalls,
                  "Incorect number of send method calls.. Expected: " << TEST_NUM_OF_SEND_METHOD_CALLS << ", but got: " << testNumOfSendMethodCalls)
    ASSERT_EQUALS(TEST_TOTAL_DELAY, testTotalDelay,
                  "Incorect total delay.. Expected: " << TEST_TOTAL_DELAY << ", but got: " << testTotalDelay)

    return 0;
}

void send(keyboard_api::KeyboardReport *kr)
{
    // char outBuffer[512] = {0};
    // cout << "Send report" << endl;
    // dumpHidKeyboardReport(kr, outBuffer);
    // cout << outBuffer << endl;
    testNumOfSendMethodCalls++;
}

void testMacroCommandHandlerDelay(uint32_t delay)
{
    testTotalDelay += delay;
}
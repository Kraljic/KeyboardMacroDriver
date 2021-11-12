#include "ps2_keyboard_test.h"
#include <iostream>

#include "../Inc/ps2_keyboard_reader.h"
#include "../Inc/ps2_key.h"

using namespace std;
using namespace ps2_keyboard;

#define PS2_KBR_TEST_IN_BUFF_SIZE 128

uint8_t ps2KeyboardTestInputDataBuffer[PS2_KBR_TEST_IN_BUFF_SIZE] = {
    PS2_KEY_A,                   // Press A
    PS2_KEY_REALESED, PS2_KEY_A, // Release A

    PS2_KEY_MOD_LSHIFT,                   // Press left shit
    PS2_KEY_REALESED, PS2_KEY_MOD_LSHIFT, // Release left shif

    0xE0, (PS2_KEY_LEFT & 0xFF),                   // Press Left Arrow (Extended key)
    0xE0, PS2_KEY_REALESED, (PS2_KEY_LEFT & 0xFF), // Release Left Arrow (Extended key)

    0};

uint16_t counter = 0;

uint8_t nextByte()
{
    return ps2KeyboardTestInputDataBuffer[counter++];
}

uint8_t testKeyAvailable();
uint8_t testKeyNotAvailable();
uint8_t testKeyEquals(Ps2Key *key1, Ps2Key *key2);

uint8_t testKeyEvent(Ps2Key *key, uint8_t receiveBytes);

#define KEY_DESCRIPTOR(                                   \
    key, keyCode, extFlag, upFlag, specFlag, errFlag)     \
    (key).ps2Code = (uint8_t)(keyCode)&0xFF;              \
    (key).ps2Extended = (extFlag) ? PS2_KEY_EXTENDED : 0; \
    (key).ps2Special = (specFlag) ? PS2_KEY_SPECIAL : 0;  \
    (key).released = (upFlag) ? PS2_KEY_REALESED : 0;     \
    (key).error = (errFlag) ? 1 : 0;                      \
    (key).done = 1;

/** returns 0 if test was successful. */
int test::ps2_keyboard_reader_test()
{
    Ps2Key key = {0};

    // Test key A press
    KEY_DESCRIPTOR(key, PS2_KEY_A, 0, 0, 0, 0)
    if (testKeyEvent(&key, 1))
        return 1;
    KEY_DESCRIPTOR(key, PS2_KEY_A, 0, 1, 0, 0)
    if (testKeyEvent(&key, 2))
        return 1;

    // Test key LSHIFT press
    KEY_DESCRIPTOR(key, PS2_KEY_MOD_LSHIFT, 0, 0, 0, 0)
    if (testKeyEvent(&key, 1))
        return 1;
    KEY_DESCRIPTOR(key, PS2_KEY_MOD_LSHIFT, 0, 1, 0, 0)
    if (testKeyEvent(&key, 2))
        return 1;

    // Test key LEFT ARROW (extended) press
    KEY_DESCRIPTOR(key, PS2_KEY_LEFT, 1, 0, 0, 0)
    if (testKeyEvent(&key, 2))
        return 1;
    KEY_DESCRIPTOR(key, PS2_KEY_LEFT, 1, 1, 0, 0)
    if (testKeyEvent(&key, 3))
        return 1;

    return 0;
}

uint8_t testKeyEvent(Ps2Key *key, uint8_t receiveBytes)
{
    if (testKeyNotAvailable())
        return 1;

    while (receiveBytes-- > 0)
        Ps2KeyboardReader::receivePs2Date(nextByte());

    if (testKeyAvailable())
        return 1;

    Ps2Key scanedKey = Ps2KeyboardReader::getNextKey();
    if (testKeyEquals(key, &scanedKey))
        return 1;

    return 0;
}

uint8_t testKeyAvailable()
{
    if (!Ps2KeyboardReader::keyAvailable())
    {
        cout << "Test failed: No key available!" << endl;
        return 1;
    }

    return 0;
}
uint8_t testKeyNotAvailable()
{
    if (Ps2KeyboardReader::keyAvailable())
    {
        cout << "Test failed: Key is available but it should not be!" << endl;
        return 1;
    }

    return 0;
}

uint8_t testKeyEquals(Ps2Key *key1, Ps2Key *key2)
{
    if (key1->error != key2->error)
    {
        cout << "Key missmatch in ERROR.." << endl;
        return 1;
    }
    if (key1->done != key2->done)
    {
        cout << "Key missmatch in DONE.." << endl;
        return 1;
    }
    if (key1->ps2Code != key2->ps2Code)
    {
        cout << "Key missmatch in PS2_CODE.." << endl;
        return 1;
    }
    if (key1->ps2Extended != key2->ps2Extended)
    {
        cout << "Key missmatch in PS2_EXTENDED.." << endl;
        return 1;
    }
    if (key1->ps2Special != key2->ps2Special)
    {
        cout << "Key missmatch in PS2_SPECIAL.." << endl;
        return 1;
    }
    if (key1->released != key2->released)
    {
        cout << "Key missmatch in RELEASED.." << endl;
        return 1;
    }

    return 0;
}
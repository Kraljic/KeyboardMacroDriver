#include <iostream>

#include "../../_TestUtil/_test_util.h"

#include "ascii_to_hid_transcoder_test.h"

using namespace transcoders;

#define SHIFT(key) ((key) | (HID_KEY_MOD_LSHIFT << 8))
int test::ascii_to_hid_test()
{
    uint16_t result = 0;

    result = AsciiToHidTranscoder::asciiToHid('a');
    ASSERT_EQUALS(HID_KEY_A, result, "Incorect translation of char 'a' to hid.")

    result = AsciiToHidTranscoder::asciiToHid('A');
    ASSERT_EQUALS(SHIFT(HID_KEY_A), result, "Incorect translation of char 'A' to hid.")

    result = AsciiToHidTranscoder::asciiToHid('z');
    ASSERT_EQUALS(HID_KEY_Z, result, "Incorect translation of char 'z' to hid.")

    result = AsciiToHidTranscoder::asciiToHid('Z');
    ASSERT_EQUALS(SHIFT(HID_KEY_Z), result, "Incorect translation of char 'Z' to hid.")

    result = AsciiToHidTranscoder::asciiToHid('1');
    ASSERT_EQUALS(HID_KEY_1, result, "Incorect translation of char '1' to hid.")

    result = AsciiToHidTranscoder::asciiToHid('!');
    ASSERT_EQUALS(SHIFT(HID_KEY_1), result, "Incorect translation of char '!' to hid.")

    result = AsciiToHidTranscoder::asciiToHid('0');
    ASSERT_EQUALS(HID_KEY_0, result, "Incorect translation of char '0' to hid.")

    result = AsciiToHidTranscoder::asciiToHid(')');
    ASSERT_EQUALS(SHIFT(HID_KEY_0), result, "Incorect translation of char ')' to hid.")

    result = AsciiToHidTranscoder::asciiToHid('\n');
    ASSERT_EQUALS(HID_KEY_ENTER, result, "Incorect translation of char '\\n' to hid.")

    result = AsciiToHidTranscoder::asciiToHid(' ');
    ASSERT_EQUALS(HID_KEY_SPACE, result, "Incorect translation of char '{space}' to hid.")

    return 0;
}
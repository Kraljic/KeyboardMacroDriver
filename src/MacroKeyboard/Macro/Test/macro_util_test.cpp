#include "macro_test.h"
#include "../../_TestUtil/_test_util.h"

#include "../Inc/macro_util.h"
#include "../../KeyboardApi/keyboard_report.h"

using namespace macro_api;
using namespace keyboard_api;

#define TEST_EXPECTED_HASH(val1, val2, val3, val4) ((val1) | (val2) << 8 | (val3) << 16 | (val4) << 24)

int test::macro_util_test()
{
    KeyboardReport kr = {0};
    kr.modKeys = 0x13;

    uint32_t expected;
    uint32_t triggerHash;

    kr.keys[0] = 0x42;
    expected = TEST_EXPECTED_HASH(0x42, 0x00, 0x00, 0x13);
    triggerHash = MacroUtil::getMacroTriggerCode(kr);
    ASSERT_EQUALS(expected, triggerHash,
                  "Incorect trigger hash code.. Expected: " << (void *)expected << "; But got: " << (void *)triggerHash)

    kr.keys[1] = 0x63;
    expected = TEST_EXPECTED_HASH(0x63, 0x42, 0x00, 0x13);
    triggerHash = MacroUtil::getMacroTriggerCode(kr);
    ASSERT_EQUALS(expected, triggerHash,
                  "Incorect trigger hash code.. Expected: " << (void *)expected << "; But got: " << (void *)triggerHash)

    kr.keys[2] = 0x58;
    expected = TEST_EXPECTED_HASH(0x63, 0x58, 0x42, 0x13);
    triggerHash = MacroUtil::getMacroTriggerCode(kr);
    ASSERT_EQUALS(expected, triggerHash,
                  "Incorect trigger hash code.. Expected: " << (void *)expected << "; But got: " << (void *)triggerHash)

    kr.keys[3] = 0x71;
    expected = TEST_EXPECTED_HASH(0x71, 0x63, 0x58, 0x13);
    triggerHash = MacroUtil::getMacroTriggerCode(kr);
    ASSERT_EQUALS(expected, triggerHash,
                  "Incorect trigger hash code.. Expected: " << (void *)expected << "; But got: " << (void *)triggerHash)
    return 0;
}
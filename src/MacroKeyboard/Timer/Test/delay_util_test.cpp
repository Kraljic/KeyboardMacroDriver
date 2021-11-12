#include "timer_test.h"
#include "../../_TestUtil/_test_util.h"
#include "../Inc/delay_util.h"

using namespace delay_util;

uint32_t totalTime = 0;

void delay(uint32_t ms);

#define SHORT_DELAY_TEST 5
#define LONG_DELAY_TEST 86
#define LONG_LONG_DELAY_TEST 487

int test::delay_util_test()
{
    Delay::init(&delay);

    Delay::delayShort(SHORT_DELAY_TEST);
    Delay::delayLong(LONG_DELAY_TEST);
    Delay::delayLongLong(LONG_LONG_DELAY_TEST);

    uint32_t expected = SHORT_DELAY_TEST * Delay::DELAY_SHORT_TICK_DURATION +
                        LONG_DELAY_TEST * Delay::DELAY_LONG_TICK_DURATION +
                        LONG_LONG_DELAY_TEST * Delay::DELAY_LONG_LONG_TICK_DURATION;

    ASSERT_EQUALS(expected, totalTime, "Incorect total delay.")
    ASSERT_NOT_EQUALS(expected + 1, totalTime, "Incorect total delay.")

    return 0;
}

void delay(uint32_t ms)
{
    totalTime += ms;
}
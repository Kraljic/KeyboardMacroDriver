#ifndef _DELAY_UTIL_H
#define _DELAY_UTIL_H

#include <inttypes.h>

namespace delay_util
{
    /** Must be initialized with delay function reference before first use of delay methods. */
    class Delay
    {
    private:
        static void (*delayProto)(uint32_t);

    public:
        /** Duration of short delay tick in milliseconds. */
        static const uint32_t DELAY_SHORT_TICK_DURATION = 10;

        /** Duration of long delay tick in milliseconds. */
        static const uint32_t DELAY_LONG_TICK_DURATION = 100;

        /** Duration of long long delay tick in milliseconds. */
        static const uint32_t DELAY_LONG_LONG_TICK_DURATION = 10;

        /** Requers delay function reference. */
        static void init(void (*delayProto)(uint32_t));

        /** Provides delay in short ticks. */
        static void delayShort(uint8_t ticks);

        /** Provides delay in long ticks. */
        static void delayLong(uint8_t ticks);

        /** Provides delay in long long ticks. */
        static void delayLongLong(uint32_t ticks);
    };

}

#endif
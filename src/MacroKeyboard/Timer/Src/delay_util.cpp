#include "../Inc/delay_util.h"

namespace delay_util
{
    void (*Delay::delayProto)(uint32_t) = 0;

    void Delay::init(void (*delayProto)(uint32_t))
    {
        Delay::delayProto = delayProto;
    }

    void Delay::delayShort(uint8_t ticks)
    {
        if (*Delay::delayProto != 0)
            (*Delay::delayProto)(ticks * Delay::DELAY_SHORT_TICK_DURATION);
    }

    void Delay::delayLong(uint8_t ticks)
    {
        if (*Delay::delayProto != 0)
            (*Delay::delayProto)(ticks * Delay::DELAY_LONG_TICK_DURATION);
    }

    void Delay::delayLongLong(uint32_t ticks)
    {
        if (*Delay::delayProto != 0)
            (*Delay::delayProto)(ticks * Delay::DELAY_LONG_LONG_TICK_DURATION);
    }
}
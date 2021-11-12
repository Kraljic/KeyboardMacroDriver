#ifndef _MACRO_HEADER_H
#define _MACRO_HEADER_H

#include <inttypes.h>

namespace macro_api
{
    typedef struct
    {
        uint32_t macroTriggerCode;
        uint32_t macroBeginRelativeAddress;
    } MacroHeader;
}

#endif
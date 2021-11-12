#ifndef _MACRO_META_INFO_H
#define _MACRO_META_INFO_H

#include <inttypes.h>

namespace macro_api
{
    typedef struct
    {
        uint32_t macroHeadersRelativeStartAddress;
        uint32_t macroDataRelativeStartAddress;
        uint32_t totalSize;
        uint16_t numberOfMacros;
    } MacroMetaInfo;
}
#endif
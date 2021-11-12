#ifndef _MACRO_FINDER_H
#define _MACRO_FINDER_H

#include <inttypes.h>
#include "./macro_header.h"

namespace macro_api
{
    MacroHeader *search(void *startAddress, uint16_t numberOfItems, MacroHeader *searchItem);
}

#endif
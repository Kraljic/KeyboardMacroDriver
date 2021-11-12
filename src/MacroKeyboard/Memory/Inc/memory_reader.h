
#include <inttypes.h>
#include <stddef.h>

#ifndef _MEMORY_UTIL_H
#define _MEMORY_UTIL_H

namespace memory_access
{
    /** Get next byte and increment address by 1 */
    uint8_t getNextByte(void **dataAddr);

    /** Get next short and increment address by 2 */
    uint16_t getNextShort(void **dataAddr);

    /** Get next int and increment address by 4 */
    uint32_t getNextInt(void **dataAddr);

    /** Increments address for given number of bytes (size_t) */
    void *getNextAddress(const void *dataAddr, size_t size);
}

#endif
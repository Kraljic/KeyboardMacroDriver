#include <inttypes.h>
#include <stddef.h>

#ifndef _RELATIVE_MEMORY_ACCESS_H
#define _RELATIVE_MEMORY_ACCESS_H

namespace memory_access
{
    class RelativeMemoryAccess
    {
    private:
        const void *baseAddress;
        size_t size;

        uint8_t checkAddress(uint32_t relativeAddress);

    public:
        /** Initialize relative address space with base address and max size*/
        RelativeMemoryAccess(const void *baseAddress, size_t size);

        /** Get absolute address from relaive address */
        void *getAddress(uint32_t relativeAddress);

        uint8_t getUInt8(uint32_t relativeAddress);
        int8_t getInt8(uint32_t relativeAddress);

        uint16_t getUInt16(uint32_t relativeAddress);
        int16_t getInt16(uint32_t relativeAddress);

        uint32_t getUInt32(uint32_t relativeAddress);
        int32_t getInt32(uint32_t relativeAddress);
    };

}

#endif
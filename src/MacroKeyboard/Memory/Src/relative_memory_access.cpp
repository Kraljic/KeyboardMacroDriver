#include "../Inc/relative_memory_access.h"
#include "../Inc/memory_reader.h"

namespace memory_access
{
    RelativeMemoryAccess::RelativeMemoryAccess(const void *baseAddress, size_t size)
    {
        this->baseAddress = baseAddress;
        this->size = size;
    }

    void *RelativeMemoryAccess::getAddress(uint32_t relativeAddress)
    {
        if (relativeAddress > this->size)
            return 0;

        return memory_access::getNextAddress(this->baseAddress, relativeAddress);
    }

    uint8_t RelativeMemoryAccess::getUInt8(uint32_t relativeAddress)
    {
        void *absoluteAddress = getAddress(relativeAddress);
        if (!absoluteAddress)
            return 0;

        return getNextByte(&absoluteAddress);
    }
    int8_t RelativeMemoryAccess::getInt8(uint32_t relativeAddress)
    {
        void *absoluteAddress = getAddress(relativeAddress);
        if (!absoluteAddress)
            return 0;

        return (int8_t)getNextByte(&absoluteAddress);
    }

    uint16_t RelativeMemoryAccess::getUInt16(uint32_t relativeAddress)
    {
        void *absoluteAddress = getAddress(relativeAddress);
        if (!absoluteAddress)
            return 0;

        return getNextShort(&absoluteAddress);
    }
    int16_t RelativeMemoryAccess::getInt16(uint32_t relativeAddress)
    {
        void *absoluteAddress = getAddress(relativeAddress);
        if (!absoluteAddress)
            return 0;

        return (int16_t)getNextShort(&absoluteAddress);
    }

    uint32_t RelativeMemoryAccess::getUInt32(uint32_t relativeAddress)
    {
        void *absoluteAddress = getAddress(relativeAddress);
        if (!absoluteAddress)
            return 0;

        return getNextInt(&absoluteAddress);
    }
    int32_t RelativeMemoryAccess::getInt32(uint32_t relativeAddress)
    {
        void *absoluteAddress = getAddress(relativeAddress);
        if (!absoluteAddress)
            return 0;

        return (int32_t)getNextInt(&absoluteAddress);
    }
}
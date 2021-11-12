#include "../Inc/memory_reader.h"

namespace memory_access
{
    uint8_t getNextByte(void **dataAddr)
    {
        uint8_t *addr = (uint8_t *)*dataAddr;
        *dataAddr = addr + 1;
        return *addr;
    }

    uint16_t getNextShort(void **dataAddr)
    {
        uint16_t *addr = (uint16_t *)*dataAddr;
        *dataAddr = addr + 1;
        return *addr;
    }

    uint32_t getNextInt(void **dataAddr)
    {
        uint32_t *addr = (uint32_t *)*dataAddr;
        *dataAddr = addr + 1;
        return *addr;
    }

    void *getNextAddress(const void *dataAddr, size_t size)
    {
        return (uint8_t *)dataAddr + size;
    }
}
#include "memory_test.h"
#include <iostream>

#include "../../_TestUtil/_test_util.h"

#include "../Inc/relative_memory_access.h"
#include "../Inc/memory_reader.h"

using namespace std;
using namespace memory_access;

int test::relative_memory_access_test()
{
    void *memRef = calloc(1000, sizeof(uint8_t));

    uint16_t *first = (uint16_t *)memRef;
    uint16_t *second = (uint16_t *)(first + 1);
    uint32_t *third = (uint32_t *)(second + 1);
    uint8_t *fourth = (uint8_t *)(third + 1);
    uint16_t *fifth = (uint16_t *)(fourth + 1);

    *first = 5345;   // short
    *second = 1323;  // short
    *third = 273815; // int
    *fourth = 87;    // byte
    *fifth = 55555;  // short

    RelativeMemoryAccess memAccess = RelativeMemoryAccess(memRef, 100);

    ASSERT_EQUALS(*first, memAccess.getUInt16(0), "Read incorect number - first.");
    ASSERT_EQUALS(*second, memAccess.getUInt16(2), "Read incorect number - second.");
    ASSERT_EQUALS(*third, memAccess.getUInt32(4), "Read incorect number - third.");
    ASSERT_EQUALS(*fourth, memAccess.getUInt8(8), "Read incorect number - fourth.");
    ASSERT_EQUALS(*fifth, memAccess.getUInt16(9), "Read incorect number - fifth.");

    ASSERT_EQUALS(0, memAccess.getUInt16(-1), "Read incorect number - should be ZERO.");

    free(memRef);
    return 0;
}
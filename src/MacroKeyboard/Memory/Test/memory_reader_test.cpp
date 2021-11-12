#include "memory_test.h"
#include <iostream>

#include "../../_TestUtil/_test_util.h"
#include "../Inc/memory_reader.h"

using namespace std;
using namespace memory_access;

int test::memory_reader_test()
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

    ASSERT_EQUALS(*first, getNextShort(&memRef), "Read incorect number - first.");
    ASSERT_EQUALS(*second, getNextShort(&memRef), "Read incorect number - second.");
    ASSERT_EQUALS(*third, getNextInt(&memRef), "Read incorect number - third.");
    ASSERT_EQUALS(*fourth, getNextByte(&memRef), "Read incorect number - fourth.");
    ASSERT_EQUALS(*fifth, getNextShort(&memRef), "Read incorect number - fifth.");

    free(memRef);
    return 0;
}
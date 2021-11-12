#include "macro_test.h"
#include <iostream>

#include "../Inc/macro_finder.h"

using namespace std;
using namespace macro_api;

MacroHeader macroHeader[] = {
    {1, 1},
    {2, 2},
    {3, 3},
    {4, 4},
    {5, 5},
    {6, 6},
    {7, 7},
    {8, 8},
    {9, 9},
    {10, 10},
    {11, 11},
    {12, 12},
    {13, 13},
    {14, 14},
    {15, 15},
    {16, 16},
    {17, 17},
    {18, 18},
    {19, 19},
    {20, 20},
    {21, 21},
    {22, 22},
    {23, 23},
    {24, 24},
    {25, 25},
    {26, 26},
    {27, 27},
    {28, 28},
    {29, 29},
    {30, 30},
    {31, 31},
    {32, 32},
    {33, 33},
    {34, 34},
    {35, 35},
    {36, 36},
    {37, 37},
    {38, 38},
    {39, 39},
    {40, 40},
    {41, 41},
    {42, 42},
    {43, 43},
    {44, 44},
    {45, 45},
    {46, 46},
    {47, 47},
    {48, 48},
    {49, 49},
    {50, 50},
    {51, 51},
    {52, 52},
    {53, 53},
    {54, 54},
    {55, 55},
    {56, 56},
    {57, 57},
    {58, 58},
    {59, 59},
    {60, 60},
};

#define SEARCH(mem, searchItem, output, size, item) \
    searchItem.macroTriggerCode = (item);           \
    output = search((mem), (size), &(searchItem));

#define ASSERT_FOUND(result)          \
    if (!result)                      \
    {                                 \
        cout << "Not found!" << endl; \
        return 1;                     \
    }

#define ASSERT_NOT_FOUND(result)                                                           \
    if (result)                                                                            \
    {                                                                                      \
        cout << "Found item, but should not found! : " << found->macroTriggerCode << endl; \
        return 1;                                                                          \
    }

int test::macro_finder_test()
{
    MacroHeader searchItem = {0};
    MacroHeader *found;

    // Test EVEN number of elements search
    SEARCH(macroHeader, searchItem, found, 10, 1)
    ASSERT_FOUND(found)
    SEARCH(macroHeader, searchItem, found, 10, 10)
    ASSERT_FOUND(found)
    SEARCH(macroHeader, searchItem, found, 10, 7)
    ASSERT_FOUND(found)

    // Test ODD number of elements search
    SEARCH(macroHeader, searchItem, found, 11, 1)
    ASSERT_FOUND(found)
    SEARCH(macroHeader, searchItem, found, 11, 10)
    ASSERT_FOUND(found)
    SEARCH(macroHeader, searchItem, found, 11, 7)
    ASSERT_FOUND(found)

    // Test out of range element search
    SEARCH(macroHeader, searchItem, found, 60, 0)
    ASSERT_NOT_FOUND(found)
    SEARCH(macroHeader, searchItem, found, 60, 61)
    ASSERT_NOT_FOUND(found)

    // Test ONE element search
    SEARCH(macroHeader, searchItem, found, 1, 1)
    ASSERT_FOUND(found)
    SEARCH(macroHeader, searchItem, found, 1, 0)
    ASSERT_NOT_FOUND(found)
    SEARCH(macroHeader, searchItem, found, 1, 2)
    ASSERT_NOT_FOUND(found)

    // Test TWO elements search
    SEARCH(macroHeader, searchItem, found, 2, 1)
    ASSERT_FOUND(found)
    SEARCH(macroHeader, searchItem, found, 2, 2)
    ASSERT_FOUND(found)
    SEARCH(macroHeader, searchItem, found, 2, 0)
    ASSERT_NOT_FOUND(found)
    SEARCH(macroHeader, searchItem, found, 2, 3)
    ASSERT_NOT_FOUND(found)

    // Test THREE elements search
    SEARCH(macroHeader, searchItem, found, 3, 1)
    ASSERT_FOUND(found)
    SEARCH(macroHeader, searchItem, found, 3, 2)
    ASSERT_FOUND(found)
    SEARCH(macroHeader, searchItem, found, 3, 3)
    ASSERT_FOUND(found)
    SEARCH(macroHeader, searchItem, found, 3, 0)
    ASSERT_NOT_FOUND(found)
    SEARCH(macroHeader, searchItem, found, 3, 4)
    ASSERT_NOT_FOUND(found)

    return 0;
}

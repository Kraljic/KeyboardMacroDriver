#ifndef _ASSER_H
#define _ASSER_H

#include <iostream>
#include <inttypes.h>

#define ASSERT_EQUALS(expected, actual, errMsg)                                             \
    if ((expected) != (actual))                                                             \
    {                                                                                       \
        std::cout << "Assertion :: equals :: ERROR" << std::endl;                           \
        std::cout << "Expected: " << (expected) << "\t\tActual: " << (actual) << std::endl; \
        std::cout << errMsg << std::endl;                                                   \
        throw std::runtime_error("ASSERT_EQUALS");                                          \
    }

#define ASSERT_NOT_EQUALS(val1, val2, errMsg)                                            \
    if ((val1) == (val2))                                                                \
    {                                                                                    \
        std::cout << "Assertion :: not equals :: ERROR" << std::endl;                    \
        std::cout << "1st value: " << (val1) << "\t 2nd value: " << (val2) << std::endl; \
        std::cout << errMsg << std::endl;                                                \
        throw std::runtime_error("ASSERT_NOT_EQUALS");                                   \
    }

#define PRINT_HEX(val) std::cout << (void *)(val) << std::endl;
#define PRINT_NUM(val) std::cout << (uint32_t)(val) << std::endl;

#endif
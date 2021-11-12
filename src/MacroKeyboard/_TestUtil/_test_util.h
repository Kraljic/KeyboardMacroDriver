#include <iostream>

#ifndef __TEST_UTIL_H
#define __TEST_UTIL_H

#define ASSERT_EQUALS(val1, val2, errMsg) \
    if ((val1) != (val2))                 \
    {                                     \
        std::cout << errMsg << std::endl; \
        return 1;                         \
    }

#define ASSERT_NOT_EQUALS(val1, val2, errMsg) \
    if ((val1) == (val2))                     \
    {                                         \
        std::cout << errMsg << std::endl;     \
        return 1;                             \
    }

#endif
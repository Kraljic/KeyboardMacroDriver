#ifndef _KEYBOARD_REPORT_H
#define _KEYBOARD_REPORT_H

#include <inttypes.h>

#define KEYBOARD_REPORT_ID_ERROR 0
#define KEYBOARD_REPORT_ID 1
#define KEYBOARD_REPORT_KEY_NUM 5

namespace keyboard_api
{
    typedef struct
    {
        uint8_t reportId;
        uint8_t modKeys;
        uint8_t _;
        uint8_t keys[KEYBOARD_REPORT_KEY_NUM];
    } KeyboardReport;

} // namespace keyboard_api

#endif

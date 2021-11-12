
#include <inttypes.h>
#include "../../KeyboardApi/keyboard_report.h"

#ifndef _MACRO_KEYBOARD_CONFIG
#define _MACRO_KEYBOARD_CONFIG

namespace macro_keyboard
{
    typedef struct
    {
        uint8_t reportId;

        void *macroDataAddress;
        void (*delayMethod)(uint32_t);
        void (*sendReportMethod)(keyboard_api::KeyboardReport *);

    } MacroKeyboardConfig;
}

#endif
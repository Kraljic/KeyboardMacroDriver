#ifndef _MACRO_UTIL_H
#define _MACRO_UTIL_H

#include <inttypes.h>
#include "../../KeyboardApi/keyboard_report.h"

namespace macro_api
{
    class MacroUtil
    {
    private:
        MacroUtil();

        static int compDesc(const void *elem1, const void *elem2);

    public:
        /** Get macro trigger code from keyboardReport. */
        static uint32_t getMacroTriggerCode(keyboard_api::KeyboardReport keyboardReport);
    };

}

#endif
#include "../Inc/macro_util.h"

#include <stdlib.h>

using namespace keyboard_api;

namespace macro_api
{
    MacroUtil::MacroUtil() {}

    int MacroUtil::compDesc(const void *elem1, const void *elem2)
    {
        int a = *(uint8_t *)elem1;
        int b = *(uint8_t *)elem2;
        return -(a - b);
    }

    uint32_t MacroUtil::getMacroTriggerCode(KeyboardReport keyboardReport)
    {
        uint32_t triggerCode;
        uint8_t *hash = (uint8_t *)&triggerCode;

        qsort(keyboardReport.keys, KEYBOARD_REPORT_KEY_NUM, sizeof(uint8_t), MacroUtil::compDesc);

        hash[0] = keyboardReport.keys[0];
        hash[1] = keyboardReport.keys[1];
        hash[2] = keyboardReport.keys[2];
        hash[3] = keyboardReport.modKeys;

        return triggerCode;
    }
}
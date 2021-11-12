#include "../Inc/macro_finder.h"

namespace macro_api
{
    MacroHeader *getMiddle(MacroHeader *start, MacroHeader *end);

    MacroHeader *search(void *startAddress, uint16_t numberOfItems, MacroHeader *searchItem)
    {
        if (numberOfItems == 0)
            return 0;

        MacroHeader *start = (MacroHeader *)startAddress;
        MacroHeader *end = ((MacroHeader *)startAddress) + (numberOfItems - 1);

        // Check if first item is larger than item that we search for
        if (start->macroTriggerCode > searchItem->macroTriggerCode)
            return 0;
        // Check if last item is smaller than item that we search for
        if (end->macroTriggerCode < searchItem->macroTriggerCode)
            return 0;

        MacroHeader *current = getMiddle(start, end);
        do
        {
            if (current->macroTriggerCode == searchItem->macroTriggerCode)
                return current;
            else if (current->macroTriggerCode < searchItem->macroTriggerCode)
                current = getMiddle(start = current + 1, end);
            else
                current = getMiddle(start, end = current - 1);
        } while (start != end);

        if (current->macroTriggerCode == searchItem->macroTriggerCode)
            return current;

        return 0;
    }

    MacroHeader *getMiddle(MacroHeader *start, MacroHeader *end)
    {
        if (start >= end)
            return start;

        uint8_t size = sizeof(MacroHeader);
        uint16_t items = (end - start) + 1;
        uint16_t half = items / 2;

        return start + half;
    }
}
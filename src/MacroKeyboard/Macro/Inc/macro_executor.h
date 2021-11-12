#ifndef _MACRO_EXECUTOR_H
#define _MACRO_EXECUTOR_H

#include <inttypes.h>

#include "macro_meta_info.h"
#include "macro_command_handler.h"
#include "../../Memory/Inc/relative_memory_access.h"

using namespace memory_access;

namespace macro_api
{
    class MacroExecutor
    {
    private:
        const void *baseAddress;

        MacroMetaInfo *macroMeta;
        RelativeMemoryAccess *memoryAccess;
        MacroCommandHandler *commandHandler;

        void *headerAddress;
        void *dataAddress;

    public:
        static const uint8_t EXECUTED = 0;
        static const uint8_t NOT_EXECUTED = 1;

        MacroExecutor(const void *baseAddress, MacroCommandHandler *commandHandler);

        /** Execute macro with that matches macroCode
         * 
         * @return 0 if ok;<br>\n or 1 if error / not found
        */
        uint8_t execute(uint32_t macroCode);
    };

}

#endif
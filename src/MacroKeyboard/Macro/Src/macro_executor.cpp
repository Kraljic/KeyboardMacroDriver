#include "../Inc/macro_executor.h"

#include "../Inc/macro_finder.h"
#include "../Inc/macro_command_handler.h"

namespace macro_api
{
    MacroExecutor::MacroExecutor(const void *baseAddress, MacroCommandHandler *commandHandler)
    {
        this->baseAddress = baseAddress;
        this->memoryAccess = new RelativeMemoryAccess(this->baseAddress, this->macroMeta->totalSize);
        macroMeta = (MacroMetaInfo *)this->baseAddress;

        this->headerAddress = this->memoryAccess->getAddress(this->macroMeta->macroHeadersRelativeStartAddress);
        this->dataAddress = this->memoryAccess->getAddress(this->macroMeta->macroDataRelativeStartAddress);

        this->commandHandler = commandHandler;
    }

    uint8_t MacroExecutor::execute(uint32_t macroCode)
    {
        // todo:: write simple test, other smaller units are tested.
        MacroHeader searchMacro = {macroCode};

        MacroHeader *foundMacro = search(this->headerAddress, this->macroMeta->numberOfMacros, &searchMacro);

        if (foundMacro != 0)
        {
            void *macroAddress = this->memoryAccess->getAddress(foundMacro->macroBeginRelativeAddress);

            while ((macroAddress = this->commandHandler->handleCommand(macroAddress)) != 0)
                asm("NOP");

            return MacroExecutor::EXECUTED;
        }

        return MacroExecutor::NOT_EXECUTED;
    }
}
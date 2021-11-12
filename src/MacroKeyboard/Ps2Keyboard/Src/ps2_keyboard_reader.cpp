#include "../Inc/ps2_keyboard_reader.h"

namespace ps2_keyboard
{
    uint8_t Ps2KeyboardReader::ps2InputBuffer[PS2_KEYBOARD_INPUT_BUFFER_SIZE] = {0};
    uint8_t Ps2KeyboardReader::ps2InputHead = 0;
    uint8_t Ps2KeyboardReader::ps2InputTail = 0;

    void _incrementBufferPointer(uint8_t *bufferPointer)
    {
        (*bufferPointer)++;
        if (*bufferPointer >= PS2_KEYBOARD_INPUT_BUFFER_SIZE)
            *bufferPointer = 0;
    }

    void Ps2KeyboardReader::receivePs2Date(uint8_t data)
    {
        ps2InputBuffer[ps2InputHead] = data;

        _incrementBufferPointer(&ps2InputHead);
    }

    bool Ps2KeyboardReader::keyAvailable()
    {
        return ps2InputTail != ps2InputHead;
    }

    Ps2Key Ps2KeyboardReader::getNextKey()
    {
        uint8_t nextByte;
        Ps2Key tempKey = {0};

        while (!tempKey.done)
        {
            nextByte = _readNextByte();
            _decodeByte(nextByte, &tempKey);
        }

        return tempKey;
    }

    uint8_t Ps2KeyboardReader::_readNextByte()
    {
        uint8_t inputByte;

        while (ps2InputHead == ps2InputTail)
            asm("NOP");

        inputByte = ps2InputBuffer[ps2InputTail];

        _incrementBufferPointer(&ps2InputTail);

        return inputByte;
    }
    void Ps2KeyboardReader::_decodeByte(uint8_t byte, Ps2Key *key)
    {
        switch (byte)
        {
        case PS2_KEY_EXTENDED:
            key->ps2Extended = PS2_KEY_EXTENDED;
            break;
        case PS2_KEY_REALESED:
            key->released = PS2_KEY_REALESED;
            break;
        case PS2_KEY_SPECIAL:
            key->ps2Special = PS2_KEY_SPECIAL;
            break;
        default:
            key->ps2Code = byte;
            key->done = 1;
        }
    }
}

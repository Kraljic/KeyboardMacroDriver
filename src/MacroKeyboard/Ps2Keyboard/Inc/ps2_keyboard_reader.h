#ifndef PS2_KEYBOARD_READER_H
#define PS2_KEYBOARD_READER_H

#include <inttypes.h>
#include "ps2_key.h"
#include "ps2_key_codes.h"

#define PS2_KEYBOARD_INPUT_BUFFER_SIZE 64

namespace ps2_keyboard
{
    /** Used for reading PS2 keys. */
    class Ps2KeyboardReader
    {
    private:
        static uint8_t ps2InputBuffer[PS2_KEYBOARD_INPUT_BUFFER_SIZE];
        static uint8_t ps2InputHead;
        static uint8_t ps2InputTail;

        static uint8_t _readNextByte();
        static void _decodeByte(uint8_t byte, Ps2Key *key);

    public:
        /** Should be called when device receives data from PS2 keyboard.*/
        static void receivePs2Date(uint8_t data);

        /** Returns true if there are unhandled data in buffer. */
        static bool keyAvailable();

        /** Returns decoded key from PS2 keyboard, it will set error flag to true if key is invalid. */
        static Ps2Key getNextKey();
    };

}

#endif
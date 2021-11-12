#ifndef MACRO_COMMAND_H
#define MACRO_COMMAND_H

/**
 * Bits:
 * 7 6 5 4  3 2 1 0
 * x x x x  x x x x
 * | | | |  | | | |
 * | | | |  | | | ---> Payload size (LSB)
 * | | | |  | | -----> Payload size
 * | | | |  | -------> Payload size (MSB)
 * | | | |  ---------> Mod key
 * | | | |
 * | | | ------------> Command (LSB)
 * | | --------------> Command
 * | ----------------> Command (MSB)
 * ------------------> Extended command flag
*/

// Mask for extended command check
#define CMD_EXTENDED 0x80
#define CMD_PAYLOAD_SIZE_MASK 0x07
#define CMD_MOD_KEY_MASK 0x08
#define CMD_COMMAND_NUMBER_OF_BITS 4
#define CMD_PAYLOAD_SIZE_NUMBER_OF_BITS 3

// End command
#define CMD_END 0x00

// Commands for keys
#define CMD_KEY_DOWN 0x01
#define CMD_KEY_UP 0x02
#define CMD_KEY_PRESS 0x03

// Commands for delay
#define CMD_DELAY_SHORT 0x04
#define CMD_DELAY_LONG 0x05
#define CMD_DELAY_LONG_LONG 0x06

// Extended commands
#define CMD_KEY_STREAM 0x81

#endif
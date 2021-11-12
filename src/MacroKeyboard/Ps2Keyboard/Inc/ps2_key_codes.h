#ifndef PS2_KEY_CODES_H
#define PS2_KEY_CODES_H

// PS2 special bytes
#define PS2_KEY_REALESED 0xF0
#define PS2_KEY_EXTENDED 0xE0
#define PS2_KEY_SPECIAL 0xE1

#define PS2_KEY_FAKE_SHIFT 0xE012

#define PS2_KEY_MOD_LCTRL 0x0014
#define PS2_KEY_MOD_LSHIFT 0x0012
#define PS2_KEY_MOD_LALT 0x0011
#define PS2_KEY_MOD_LMETA 0xE01F
#define PS2_KEY_MOD_RCTRL 0xE014
#define PS2_KEY_MOD_RSHIFT 0x0059
#define PS2_KEY_MOD_RALT 0xE011
#define PS2_KEY_MOD_RMETA 0xE027

#define PS2_KEY_A 0x001C // Keyboard a and A
#define PS2_KEY_B 0x0032 // Keyboard b and B
#define PS2_KEY_C 0x0021 // Keyboard c and C
#define PS2_KEY_D 0x0023 // Keyboard d and D
#define PS2_KEY_E 0x0024 // Keyboard e and E
#define PS2_KEY_F 0x002B // Keyboard f and F
#define PS2_KEY_G 0x0034 // Keyboard g and G
#define PS2_KEY_H 0x0033 // Keyboard h and H
#define PS2_KEY_I 0x0043 // Keyboard i and I
#define PS2_KEY_J 0x003B // Keyboard j and J
#define PS2_KEY_K 0x0042 // Keyboard k and K
#define PS2_KEY_L 0x004B // Keyboard l and L
#define PS2_KEY_M 0x003A // Keyboard m and M
#define PS2_KEY_N 0x0031 // Keyboard n and N
#define PS2_KEY_O 0x0044 // Keyboard o and O
#define PS2_KEY_P 0x004D // Keyboard p and P
#define PS2_KEY_Q 0x0015 // Keyboard q and Q
#define PS2_KEY_R 0x002D // Keyboard r and R
#define PS2_KEY_S 0x001B // Keyboard s and S
#define PS2_KEY_T 0x002C // Keyboard t and T
#define PS2_KEY_U 0x003C // Keyboard u and U
#define PS2_KEY_V 0x002A // Keyboard v and V
#define PS2_KEY_W 0x001D // Keyboard w and W
#define PS2_KEY_X 0x0022 // Keyboard x and X
#define PS2_KEY_Y 0x0035 // Keyboard y and Y
#define PS2_KEY_Z 0x001A // Keyboard z and Z

#define PS2_KEY_1 0x0016 // Keyboard 1 and !
#define PS2_KEY_2 0x001E // Keyboard 2 and @
#define PS2_KEY_3 0x0026 // Keyboard 3 and #
#define PS2_KEY_4 0x0025 // Keyboard 4 and $
#define PS2_KEY_5 0x002E // Keyboard 5 and %
#define PS2_KEY_6 0x0036 // Keyboard 6 and ^
#define PS2_KEY_7 0x003D // Keyboard 7 and &
#define PS2_KEY_8 0x003E // Keyboard 8 and *
#define PS2_KEY_9 0x0046 // Keyboard 9 and (
#define PS2_KEY_0 0x0045 // Keyboard 0 and )

#define PS2_KEY_ENTER 0x005A      // Keyboard Return (ENTER)
#define PS2_KEY_ESC 0x0076        // Keyboard ESCAPE
#define PS2_KEY_BACKSPACE 0x0066  // Keyboard DELETE (Backspace)
#define PS2_KEY_TAB 0x000D        // Keyboard Tab
#define PS2_KEY_SPACE 0x0029      // Keyboard Spacebar
#define PS2_KEY_MINUS 0x004E      // Keyboard - and _
#define PS2_KEY_EQUAL 0x0055      // Keyboard = and +
#define PS2_KEY_LEFTBRACE 0x0054  // Keyboard [ and {
#define PS2_KEY_RIGHTBRACE 0x005B // Keyboard ] and }
#define PS2_KEY_BACKSLASH 0x005D  // Keyboard \ and |
#define PS2_KEY_LESSTHAN 0x0061   // Keyboard < and >
#define PS2_KEY_SEMICOLON 0x004C  // Keyboard ; and :
#define PS2_KEY_APOSTROPHE 0x0052 // Keyboard ' and "
#define PS2_KEY_GRAVE 0x000E      // Keyboard ` and ~
#define PS2_KEY_COMMA 0x0041      // Keyboard , and <
#define PS2_KEY_DOT 0x0049        // Keyboard . and >
#define PS2_KEY_SLASH 0x004A      // Keyboard / and ?
#define PS2_KEY_CAPSLOCK 0x0058   // Keyboard Caps Lock
#define PS2_KEY_MENU 0xE02F       // Keyboard Open Menu

#define PS2_KEY_F1 0x0005  // Keyboard F1
#define PS2_KEY_F2 0x0006  // Keyboard F2
#define PS2_KEY_F3 0x0004  // Keyboard F3
#define PS2_KEY_F4 0x000C  // Keyboard F4
#define PS2_KEY_F5 0x0003  // Keyboard F5
#define PS2_KEY_F6 0x000B  // Keyboard F6
#define PS2_KEY_F7 0x0083  // Keyboard F7
#define PS2_KEY_F8 0x000A  // Keyboard F8
#define PS2_KEY_F9 0x0001  // Keyboard F9
#define PS2_KEY_F10 0x0009 // Keyboard F10
#define PS2_KEY_F11 0x0078 // Keyboard F11
#define PS2_KEY_F12 0x0007 // Keyboard F12

#define PS2_KEY_SYSRQ 0xE07C      // Keyboard Print Screen
#define PS2_KEY_SCROLLLOCK 0x007E // Keyboard Scroll Lock
//#define PS2_KEY_PAUSE 0x // Keyboard Pause - NOT SUPPORTED

#define PS2_KEY_INSERT 0xE070   // Keyboard Insert
#define PS2_KEY_HOME 0xE06C     // Keyboard Home
#define PS2_KEY_PAGEUP 0xE07D   // Keyboard Page Up
#define PS2_KEY_DELETE 0xE071   // Keyboard Delete Forward
#define PS2_KEY_END 0xE069      // Keyboard End
#define PS2_KEY_PAGEDOWN 0xE07A // Keyboard Page Down
#define PS2_KEY_RIGHT 0xE074    // Keyboard Right Arrow
#define PS2_KEY_LEFT 0xE06B     // Keyboard Left Arrow
#define PS2_KEY_DOWN 0xE072     // Keyboard Down Arrow
#define PS2_KEY_UP 0xE075       // Keyboard Up Arrow

#define PS2_KEY_NUMLOCK 0x0077    // Keyboard Num Lock and Clear
#define PS2_KEY_KPSLASH 0xE04A    // Keypad /
#define PS2_KEY_KPASTERISK 0x007C // Keypad *
#define PS2_KEY_KPMINUS 0x007B    // Keypad -
#define PS2_KEY_KPPLUS 0x0079     // Keypad +
#define PS2_KEY_KPENTER 0xE05A    // Keypad ENTER
#define PS2_KEY_KPDOT 0x0071      // Keypad . and Delete
#define PS2_KEY_KP1 0x0069        // Keypad 1 and End
#define PS2_KEY_KP2 0x0072        // Keypad 2 and Down Arrow
#define PS2_KEY_KP3 0x007A        // Keypad 3 and PageDn
#define PS2_KEY_KP4 0x006B        // Keypad 4 and Left Arrow
#define PS2_KEY_KP5 0x0073        // Keypad 5
#define PS2_KEY_KP6 0x0074        // Keypad 6 and Right Arrow
#define PS2_KEY_KP7 0x006C        // Keypad 7 and Home
#define PS2_KEY_KP8 0x0075        // Keypad 8 and Up Arrow
#define PS2_KEY_KP9 0x007D        // Keypad 9 and Page Up
#define PS2_KEY_KP0 0x0070        // Keypad 0 and Insert

#endif

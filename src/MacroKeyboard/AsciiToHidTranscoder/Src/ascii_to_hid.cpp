#include "../Inc/ascii_to_hid.h"

namespace transcoders
{
    uint16_t AsciiToHidTranscoder::asciiToHid(char c)
    {
        uint16_t shiftDown = 0;

        if ((c >= 'A') && (c <= 'Z'))
        {
            c = tolower(c);
            shiftDown = SHIFT;
        }
        if ((c >= 'a') && (c <= 'z'))
        {
            return (((c -= 'a') + HID_KEY_A) | shiftDown);
        }
        if ((c >= '1') && (c <= '9'))
        {
            return ((c -= '1') + HID_KEY_1);
        }

        switch (c)
        {
        case '!':
            return (HID_KEY_1 | SHIFT);
        case '@':
            return (HID_KEY_2 | SHIFT);
        case '#':
            return (HID_KEY_3 | SHIFT);
        case '$':
            return (HID_KEY_4 | SHIFT);
        case '%':
            return (HID_KEY_5 | SHIFT);
        case '^':
            return (HID_KEY_6 | SHIFT);
        case '&':
            return (HID_KEY_7 | SHIFT);
        case '*':
            return (HID_KEY_8 | SHIFT);
        case '(':
            return (HID_KEY_9 | SHIFT);
        case ')':
            return (HID_KEY_0 | SHIFT);
        case '0':
            return (HID_KEY_0);
        case '\n':
            return (HID_KEY_ENTER); //enter
        case '\r':
            return (HID_KEY_ENTER); //enter
        case '\b':
            return (HID_KEY_BACKSPACE); //backspace
        case '\t':
            return (HID_KEY_TAB); //tab
        case ' ':
            return (HID_KEY_SPACE); //space
        case '_':
            return (HID_KEY_MINUS | SHIFT);
        case '-':
            return (HID_KEY_MINUS);
        case '+':
            return (HID_KEY_EQUAL | SHIFT);
        case '=':
            return (HID_KEY_EQUAL);
        case '{':
            return (HID_KEY_LEFTBRACE | SHIFT);
        case '[':
            return (HID_KEY_LEFTBRACE);
        case '}':
            return (HID_KEY_RIGHTBRACE | SHIFT);
        case ']':
            return (HID_KEY_RIGHTBRACE);
        case '|':
            return (HID_KEY_BACKSLASH | SHIFT);
        case '\\':
            return (HID_KEY_BACKSLASH);
        case ':':
            return (HID_KEY_SEMICOLON | SHIFT);
        case ';':
            return (HID_KEY_SEMICOLON);
        case '"':
            return (HID_KEY_APOSTROPHE | SHIFT);
        case '\'':
            return (HID_KEY_APOSTROPHE);
        case '~':
            return (HID_KEY_GRAVE | SHIFT);
        case '`':
            return (HID_KEY_GRAVE);
        case '<':
            return (HID_KEY_COMMA | SHIFT);
        case ',':
            return (HID_KEY_COMMA);
        case '>':
            return (HID_KEY_DOT | SHIFT);
        case '.':
            return (HID_KEY_DOT);
        case '?':
            return (HID_KEY_SLASH | SHIFT);
        case '/':
            return (HID_KEY_SLASH);
        }

        return 0;
    }
}
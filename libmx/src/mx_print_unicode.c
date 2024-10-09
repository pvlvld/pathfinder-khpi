#include "../inc/libmx.h"

void mx_print_unicode(wchar_t c) {
    unsigned char utf8[4];

    if (c < 0x80) {
        write(1, &c, 1);
    } else if (c < 0x800) {
        utf8[0] = (c >> 6) | 0xC0;
        utf8[1] = (c & 0x3F) | 0x80;
        write(1, utf8, 2);
    } else if (c < 0x10000) {
        utf8[0] = (c >> 12) | 0xE0;
        utf8[1] = ((c >> 6) & 0x3F) | 0x80;
        utf8[2] = (c & 0x3F) | 0x80;
        write(1, utf8, 3);
    } else {
        utf8[0] = (c >> 18) | 0xF0;
        utf8[1] = ((c >> 12) & 0x3F) | 0x80;
        utf8[2] = ((c >> 6) & 0x3F) | 0x80;
        utf8[3] = (c & 0x3F) | 0x80;
        write(1, utf8, 4);
    }
}

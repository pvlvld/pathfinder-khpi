#include "../inc/libmx.h"

void mx_str_reverse(char *s) {
    if (!s) return;

    char *end = s;

    while (*end) end++;
    end--;

    while (s < end) {
        *s ^= *end;
        *end ^= *s;
        *s ^= *end;

        s++;
        end--;
    }
}

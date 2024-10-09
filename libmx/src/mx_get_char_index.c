#include "../inc/libmx.h"

int mx_get_char_index(const char *str, char c) {
    if (str == NULL) return -2;

    int index = 0;
    while (str[index]) {
        if (str[index] == c) return index;
        index++;
    }

    return -1;
}

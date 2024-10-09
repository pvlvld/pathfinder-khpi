#include "../inc/libmx.h"

int mx_count_words(const char *str, char c) {
    if (!str || !c) return -1;
    if (c == '\0') return 1;

    int count = 0;
    while (*str) {
        while (*str == c) str++;
        if (*str && *str != '\0') {
            count++;
            while (*str != c && *str) str++;
        }
    }
    return count;
}

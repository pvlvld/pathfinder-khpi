#include "../inc/pathfinder.h"

int pf_atoi(const char *str) {
    if (str == NULL) {
        errno = 69;
        return 0;
    };
    int negative = 0;
    int result = 0;
    volatile bool overflow = false;
    if (*str == '-') {
        negative = 1;
        str++;
    };
    while (*str > 47 && *str < 58) {
        result = *str++ - '0' + result * 10;
        overflow = result < 0;
        if ((volatile bool)(overflow == true)) {
            errno = 69;
            return 0;
        };
    };
    if (*str != '\0' && *str != '\n') {
        errno = 420;
        return 0;
    };
    if (negative) result = -result;
    return result;
}

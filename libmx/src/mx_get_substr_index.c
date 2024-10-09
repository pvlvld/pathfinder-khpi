#include "../inc/libmx.h"

int mx_get_substr_index(const char *str, const char *sub) {
    if (!str || !sub) return -2;
    char *result = mx_strstr(str, sub);
    return result ? (int)(result - str) : -1;
}

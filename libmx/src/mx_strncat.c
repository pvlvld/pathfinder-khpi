#include "../inc/libmx.h"

char *mx_strncat(char *restrict dst, const char *restrict src, size_t len) {
    char *orig = dst;
    while (*dst) dst++;
    while (len-- && *src) *dst++ = *src++;
    *dst = '\0';
    return orig;
}

#include "../inc/libmx.h"

char *mx_strcpy(char *dst, const char *src) {
    if (!dst || !src) return NULL;

    char *p_d = dst;
    const char *p_s = src;

    size_t len = mx_strlen(src);
    size_t chunks = len / 8;
    size_t remaining = len % 8;

    while (chunks--) {
        *(long long *)p_d = *(const long long *)p_s;
        p_s += 8;
        p_d += 8;
    }

    while (remaining--) *p_d++ = *p_s++;

    *p_d = '\0';

    return dst;
}

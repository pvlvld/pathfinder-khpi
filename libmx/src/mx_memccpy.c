#include "../inc/libmx.h"

void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n) {
    char *p_d = dst;
    const char *p_s = src;
    size_t i;
    for (i = 0; i < n; i++) {
        *p_d = *p_s;
        if (*p_s == c) return dst;
        p_s++;
        p_d++;
    }
    if (i == n) return NULL;
    return p_d;
}

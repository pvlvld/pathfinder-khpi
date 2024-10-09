#include "../inc/libmx.h"

void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n) {
    if (!src) return dst;
    char *p_d = dst;
    const char *p_s = src;
    size_t chunks = n / 8;
    size_t remaining = n % 8;

    while (chunks--) {
        *(long long *)p_d = *(const long long *)p_s;
        p_s += 8;
        p_d += 8;
    }
    while (remaining--) { *p_d++ = *p_s++; }
    *p_d = '\0';
    return dst;
}

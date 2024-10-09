#include "../inc/libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len) {
    if (dst == src || len == 0) return dst;

    char *p_d = (char *)dst;
    const char *p_s = (const char *)src;

    if (p_d < p_s) {
        while (len-- > 0) *p_d++ = *p_s++;
    } else {
        p_d += len - 1;
        p_s += len - 1;
        while (len-- > 0) *p_d-- = *p_s--;
    }

    return dst;
}

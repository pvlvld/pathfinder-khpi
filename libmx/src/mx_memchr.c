#include "../inc/libmx.h"

void *mx_memchr(const void *s, int c, size_t n) {
    const char *p_s = (const char *)s;

    for (size_t i = 0; i < n; i++) {
        if (*p_s == (char)c) return (void *)p_s;
        p_s++;
    }

    return NULL;
}

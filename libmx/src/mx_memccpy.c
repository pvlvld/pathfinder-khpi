#include "../inc/libmx.h"
#include <string.h>

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

void *memccpy(void *dst, const void *src, int c, size_t n) {
    char *q = dst;
    const char *p = src;
    const char *p_end = p + n;
    char ch = ~(char)c; /* ensure ch != c */
    for (;;) {
        if (ch == c || p >= p_end) break;
        *q++ = ch = *p++;
    }
    if (p >= p_end && ch != c) return NULL;
    return q;
}

// int main(void) {
//     const char *str =
//         "hs82nwrqqRq3G9YmCjtw84isLTMEgblB2bM9VpA5T31apSFs24PSvDaIEAIXmCUZe9nRpgN0BuztOqbYc5Y2zVZoILbwT4bMWbbYxpPIIspnAh"
//         " e8dyQL4OHkbsv9aYKPQGCcVm56b044t8SefmakymhbF0E2ree53h6nn4e6oXj6YNsAkZIX2RUa2b0nM8 b";
//     int len = strlen(str);
//     char *dst_my = mx_strnew(len);
//     char *dst_std = mx_strnew(len);

//     char *p_my = mx_memccpy(dst_my, str, ' ', len);
//     // https://android.googlesource.com/platform/bionic/+/ics-mr0/libc/string/memccpy.c
//     char *p_std = memccpy(dst_std, str, ' ', len);

//     printf("my:  %s\n", dst_my);
//     printf("std: %s\n", dst_std);
//     printf("cmp: %d\n", strcmp(dst_my, dst_std));
//     printf("p_my:  %s\n", p_my);
//     printf("p_std: %s\n", p_std);
// }

#include "../inc/libmx.h"

char *mx_strcat(char *restrict s1, const char *restrict s2) {
    char *p_start = s1;
    while (*s1) s1++;
    while (*s2) *s1++ = *s2++;
    *s1 = '\0';
    return p_start;
}

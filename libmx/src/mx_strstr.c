#include "../inc/libmx.h"

char *mx_strstr(const char *haystack, const char *needle) {
    size_t n_len = strlen(needle);
    if (!n_len) return (char *)haystack;
    while (*haystack) {
        if (!mx_memcmp(haystack++, needle, n_len)) return (char *)(haystack - 1);
    }

    return NULL;
}

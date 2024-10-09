#include "../inc/libmx.h"

char *mx_strndup(const char *s1, size_t n) {
    if (!s1) {
        errno = EINVAL;
        return NULL;
    }

    char *new_str = mx_strnew(n);

    if (!new_str) return NULL;

    mx_strncpy(new_str, s1, n);

    return new_str;
}

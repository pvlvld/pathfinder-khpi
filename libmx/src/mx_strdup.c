#include "../inc/libmx.h"

char *mx_strdup(const char *str) {
    if (str == NULL) {
        errno = EINVAL;
        return NULL;
    }

    int len = mx_strlen(str);
    char *new_str = mx_strnew(len);

    if (new_str == NULL) return NULL;

    mx_strcpy(new_str, str);

    return new_str;
}

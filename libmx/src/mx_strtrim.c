#include "../inc/libmx.h"

char *mx_strtrim(const char *str) {
    if (!str) return NULL;

    int trim_start = 0;
    int trim_end = mx_strlen(str) - 1;

    while (mx_isspace(str[trim_start])) trim_start++;

    while (trim_end >= trim_start && mx_isspace(str[trim_end])) trim_end--;

    char *trimmed = mx_strndup(str + trim_start, trim_end - trim_start + 1);

    return trimmed;
}

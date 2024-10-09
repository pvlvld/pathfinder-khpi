#include "../inc/libmx.h"

static inline char *del_extra_spaces(char *result, const char *start, const char *end) {
    int space;
    char *dst = result;

    for (const char *src = start; src <= end; src++) {
        if (mx_isspace(*src)) {
            space = 1;
            continue;
        }
        if (space && dst > result) *dst++ = ' ';
        *dst++ = *src;
        space = 0;
    }

    *dst = '\0';
    return result;
}

char *mx_del_extra_spaces(const char *str) {
    if (!str) return NULL;

    const char *start = str;
    while (mx_isspace(*start)) start++;
    if (!*start) return strdup("");

    const char *end = start + strlen(start) - 1;
    while (end > start && mx_isspace(*end)) end--;

    size_t len = end - start + 1;
    char *result = malloc((len + 1) * sizeof(char));
    if (!result) return NULL;

    return del_extra_spaces(result, start, end);
}

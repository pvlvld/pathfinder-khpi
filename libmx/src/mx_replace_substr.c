#include "../inc/libmx.h"

static inline int count_subs(const char *str, const char *sub, int sub_len) {
    int count = 0;
    while ((str = mx_strstr(str, sub))) {
        count++;
        str += sub_len;
    }
    return count;
}

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
    if (!str || !sub || !replace || !*sub) return NULL;

    int sub_len = mx_strlen(sub);
    int rep_len = mx_strlen(replace);
    int new_len = mx_strlen(str) + (rep_len - sub_len) * count_subs(str, sub, sub_len);
    char *result = mx_strnew(new_len);

    for (int i = 0; *str; str++, i++) {
        if (mx_strstr(str, sub) == str) {
            mx_strncpy(&result[i], replace, rep_len);
            i += rep_len - 1;
            str += sub_len - 1;
        } else {
            result[i] = *str;
        }
    }

    return result;
}

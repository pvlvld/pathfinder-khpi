#include "../inc/libmx.h"

int mx_count_substr(const char *str, const char *sub) {
    if (!str || !sub) return -1;

    if (*sub == '\0') return 0;

    int count = 0;
    int sub_len = mx_strlen(sub);
    const char *str_offsetted = mx_strstr(str, sub);

    while (str_offsetted != NULL) {
        count++;
        str_offsetted += sub_len;
        str_offsetted = mx_strstr(str_offsetted, sub);
    }

    return count;
}

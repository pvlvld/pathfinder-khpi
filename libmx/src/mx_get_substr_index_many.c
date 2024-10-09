
#include "../inc/libmx.h"

int mx_get_substr_index_many(const char *str, const char *sub) {
    if (!str || !sub) return -2;
    char *idx = mx_strstr(str, sub);
    return idx ? (int)(idx - str) : -1;
}

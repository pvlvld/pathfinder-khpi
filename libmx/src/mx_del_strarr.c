#include "../inc/libmx.h"

void mx_del_strarr(char ***arr) {
    if (!arr || !*arr) return;
    for (char **str = *arr; *str != NULL; str++) mx_strdel(str);
    free(*arr);
    *arr = NULL;
}

#include "../inc/libmx.h"

void mx_print_strarr(char **arr, const char *delim) {
    if (!arr || !delim) return;

    if (*arr && *arr[0]) {
        mx_printstr(*arr);
        arr++;
    }

    while (*arr) {
        mx_printstr(delim);
        mx_printstr(*arr);
        arr++;
    }

    mx_printstr("\n");
}

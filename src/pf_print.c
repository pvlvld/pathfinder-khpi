#include "../inc/pathfinder.h"

void itoa_recursive_print(int value, int index) {
    if (value == 0) return;
    itoa_recursive_print(value / 10, index + 1);
    write(1, &("0123456789"[value % 10]), 1);
}

void pf_print_int(int a, bool new_line) {
    if (a < 0) {
        a = -a;
        write(1, "-", 1);
    }
    itoa_recursive_print(a, 0);
    if (new_line) write(1, "\n", 1);
}

void pf_print_str_wrapper(const char *a, bool new_line) { pf_print_str(a, new_line, false); }

void pf_print_str(const char *a, bool new_line, bool backward) {
    if (!a) return;
    int len = mx_strlen(a);
    if (backward) {
        for (int i = len; i > 0; i--) write(1, &a[i - 1], 1);
    } else {
        write(1, a, len);
    }
    if (new_line) write(1, "\n", 1);
}

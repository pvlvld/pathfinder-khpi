#include "../inc/libmx.h"

int mx_bubble_sort(char **arr, int size) {
    int swap_count = 0;
    int swapped;
    char **end = arr + size;
    char **i;
    char **j;

    for (i = arr; i < end - 1; i++) {
        swapped = 0;
        for (j = arr; j < end - (i - arr) - 1; j++) {
            if (mx_strcmp(*j, *(j + 1)) > 0) {
                mx_swap_strings(j, j + 1);
                swap_count++;
                swapped = 1;
            }
        }
        if (!swapped) break;
    }

    return swap_count;
}

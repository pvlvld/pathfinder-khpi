#include "../inc/libmx.h"

int mx_binary_search(char **arr, int size, const char *s, int *count) {
    int left = 0;
    int right = size - 1;
    int mid;
    int cmp;
    *count = 0;

    while (left <= right) {
        mid = left + (right - left) / 2;
        cmp = mx_strcmp(arr[mid], s);
        (*count)++;

        if (cmp == 0) {
            return mid;
        } else if (cmp > 0) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    *count = 0;
    return -1;
}

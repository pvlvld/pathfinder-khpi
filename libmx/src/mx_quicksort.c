#include "../inc/libmx.h"

static inline int find_left(char **arr, int left, int right, int pivot) {
    for (int i = left; i <= right; i++) {
        if (mx_strlen(arr[i]) > mx_strlen(arr[pivot]) || i == pivot) return i;
    }
    return right;
}

static inline int find_right(char **arr, int left, int right, int pivot) {
    for (int j = right; j >= left; j--) {
        if (mx_strlen(arr[j]) < mx_strlen(arr[pivot]) || j == pivot) return j;
    }
    return left;
}

static inline void adjust_pivot(int *new_l, int *new_r, int *pivot, bool is_left) {
    if (is_left) {
        *new_l = *pivot;
        *pivot = *new_r;
    } else {
        *new_r = *pivot;
        *pivot = *new_l;
    }
}

static inline int partition(char **arr, int left, int right, int pivot) {
    int count = 0;
    int new_l = left;
    int new_r = right;
    while (new_l <= new_r) {
        new_l = find_left(arr, left, right, pivot);
        new_r = find_right(arr, left, right, pivot);
        if (new_l == pivot && new_r != pivot) {
            adjust_pivot(&new_l, &new_r, &pivot, true);
        } else if (new_r == pivot && new_l != pivot) {
            adjust_pivot(&new_l, &new_r, &pivot, false);
        }
        if (new_l != new_r) {
            mx_swap_strings(&arr[new_l], &arr[new_r]);
            count++;
        }
        new_l++;
        new_r--;
    }

    return count;
}

int mx_quicksort(char **arr, int left, int right) {
    if (left >= right) return 0;

    int pivot = (right - left) / 2 + left;
    int count = partition(arr, left, right, pivot);

    int new_l = pivot + 1;
    int new_r = pivot - 1;

    if (left < new_r) count += mx_quicksort(arr, left, new_r);
    if (new_l < right) count += mx_quicksort(arr, new_l, right);

    return count;
}

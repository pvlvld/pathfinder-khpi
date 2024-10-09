#include "../inc/libmx.h"

static inline int mx_sqrt_binary(int x, int *result) {
    int right = x / 2;
    int left = 1;
    long square;
    long mid;

    while (left <= right) {
        mid = left + (right - left) / 2;
        square = mid * mid;

        if (square == x) return *result = mid;
        if (square < x) {
            left = mid + 1;
            *result = mid;
        } else {
            right = mid - 1;
        }
    }

    return *result;
}

int mx_sqrt(int x) {
    if (x < 0) return 0;
    if (x == 0 || x == 1) return x;

    int result = 0;
    mx_sqrt_binary(x, &result);

    if (result * result == x) return result;
    return 0;
}

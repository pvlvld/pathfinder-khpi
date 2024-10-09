#include "../inc/libmx.h"

void mx_free_arr(void **arr, int length) {
    while (length-- > 0) free(arr[length]);
    free(arr);
}

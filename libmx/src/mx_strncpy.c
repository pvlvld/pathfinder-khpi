#include "../inc/libmx.h"

char *mx_strncpy(char *dst, const char *src, int len) {
    char *p_start = dst;
    while (len-- > 0 && *src) *dst++ = *src++;
    return p_start;
}

// int main(void) {
//     char *str = "7Gz2qEwYDseX1iO3W2tD dQl7f1JLSykewAV5hLDY 12";
//     char *dst_my = mx_strncat(char *__restrict dst, const char *__restrict src, size_t len);
//     char *dst_std = mx_strnew(15);
//     mx_strncpy(dst_my, str, 15);
//     strncpy(dst_std, str, 15);
//     printf("my:  %s\n", dst_my);
//     printf("std: %s\n", dst_std);
//     printf("cmp: %d\n", strcmp(dst_my, dst_std));
// }

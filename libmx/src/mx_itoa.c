#include "../inc/libmx.h"

char *mx_itoa(int number) {
    char *str = (char *)malloc(12 * sizeof(char));
    long n = number;
    int is_negative = number < 0 ? 1 : 0;
    is_negative ? n = -n : false;
    int i = 0;

    if (n == 0) {
        str[0] = '0';
        str[1] = '\0';
        return str;
    }
    while (n > 0) {
        str[i++] = (char)(n % 10) + '0';
        n /= 10;
    }
    if (is_negative) str[i++] = '-';
    str[i] = '\0';
    mx_str_reverse(str);

    return str;
}

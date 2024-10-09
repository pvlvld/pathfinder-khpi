#include "../inc/libmx.h"

void mx_printint(int n) {
    char buffer[12];
    int i = 0;
    long num = n;

    if (num < 0) {
        mx_printchar('-');
        num = -num;
    }

    if (num == 0) buffer[i++] = '0';

    while (num > 0) {
        buffer[i++] = (char)(num % 10) + '0';
        num /= 10;
    }

    while (i > 0) mx_printchar(buffer[--i]);
}

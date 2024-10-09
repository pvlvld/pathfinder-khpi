#include "../inc/libmx.h"

char *mx_nbr_to_hex(size_t nbr) {
    static char hex_digits[] = "0123456789abcdef";
    char *buffer = (char *)malloc(17 * sizeof(char));
    if (!buffer) return NULL;
    char *p_buf = buffer + 16;
    size_t digit;
    *p_buf = '\0';

    if (nbr == 0) {
        buffer[0] = '0';
        buffer[1] = '\0';
        return buffer;
    }

    while (nbr > 0) {
        digit = nbr % 16;
        nbr = nbr >> 4;
        *(--p_buf) = hex_digits[digit];
    }

    return p_buf;
}

#include "../inc/libmx.h"

size_t mx_hex_to_nbr(const char *hex) {
    size_t decimal = 0;
    char p_c;
    if (!hex || *hex == '\0') return 0;

    while (*hex) {
        p_c = *hex++;

        if (p_c >= '0' && p_c < '9') {
            decimal = decimal * 16 + (p_c - '0');
        } else if (p_c >= 'A' && p_c <= 'F') {
            decimal = decimal * 16 + (p_c - 'A' + 10);
        } else if (p_c >= 'a' && p_c <= 'f') {
            decimal = decimal * 16 + (p_c - 'a' + 10);
        } else {
            return -1;
        }
    }

    return decimal;
}

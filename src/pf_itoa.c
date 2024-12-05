#include "../inc/pathfinder.h"

char *pf_itoa_10(int value, char *buffer) {
    int i = 0;

    if (value < 0) {
        buffer[i++] = '-';
        value = -value;
    }

    int temp_value = value;
    int length = 0;
    do {
        ++length;
        temp_value /= 10;
    } while (temp_value > 0);

    buffer[i + length] = '\0';
    while (length > 0) {
        buffer[i + length - 1] = "0123456789"[value % 10];
        value /= 10;
        --length;
    }

    return buffer;
}

#include "../inc/libmx.h"

int mx_isspace(char c) {
    static const char whitespace[6] = {'\t', '\n', '\v', '\f', '\r', ' '};
    return whitespace[c % 9 % 6] == c ? 1 : 0;
}

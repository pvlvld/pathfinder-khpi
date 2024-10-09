#include "../inc/libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len) {
    if (!big || !little || big_len < little_len || little_len == 0) return NULL;

    const unsigned char *p_b = big;
    const unsigned char *p_l = little;

    for (size_t i = 0; i <= big_len - little_len; i++) {
        if (mx_memcmp(p_b, p_l, little_len) == 0) { return (void *)(p_b); }
        p_b++;
    }

    return NULL;
}

// int main(void) {

// }

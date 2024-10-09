#include "../inc/libmx.h"

void *mx_memrchr(const void *s, int c, size_t n) {
    const char *p_s = (char *)s + n;
    const char delim = c;

    while (n--) {
        p_s--;
        if (*p_s == delim) return (void *)p_s;
    }

    return NULL;
}

// int main(void) {
//     char *str = "Hello, World!";
//     char c = 'o';
//     char *p = mx_memrchr(str, c, 13);
//     printf("%s\n", p);
// }

#include "../inc/libmx.h"
#include <stdio.h>
#include <string.h>

char *mx_strchr(const char *s, int c) {
    while (*s != '\0') {
        if (*s == c) return (char *)s;
        s++;
        if (*s == c || *s == '\0') break;
    }
    return (c == '\0') ? (char *)s : NULL;
}

// int main(void) {
//     char *str = "Hello, World!";
//     char c = 'o';
//     char *p = mx_strchr(str, c);

//     printf("%s\n", p);
// }

#include "../inc/libmx.h"

char *mx_strjoin(const char *s1, const char *s2) {
    if (!s1 || !s2) {
        if (s1) return mx_strdup(s1);
        if (s2) return mx_strdup(s2);
        return NULL;
    };

    char *joined = mx_strndup(s1, mx_strlen(s1) + mx_strlen(s2));

    return joined ? mx_strcat(joined, s2) : NULL;
}

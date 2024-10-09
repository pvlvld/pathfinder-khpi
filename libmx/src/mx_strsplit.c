#include "../inc/libmx.h"

static inline char **error_allocating_str(char **arr, int str_idx) {
    mx_free_arr((void **)arr, str_idx);
    return NULL;
}

static inline char **allocate_str_array(const char *s, char c) {
    int words_count = mx_count_words(s, c);
    char **arr = malloc((words_count + 1) * sizeof(char *));
    if (!arr) return NULL;
    return arr;
}

static inline char **fill_str_array(char **arr, const char *s, char c) {
    int str_idx = 0;
    while (*s != '\0') {
        while (*s == c) s++;
        if (*s == '\0') break;
        char *p_delim = mx_strchr(s, c);
        if (p_delim == NULL) break;
        int str_end = p_delim - s;
        arr[str_idx] = mx_strndup(s, str_end);
        if (!arr[str_idx]) return error_allocating_str(arr, str_idx);
        s += str_end + 1;
        str_idx++;
    }

    if (str_idx == 0) {
        arr[0] = mx_strndup(s, mx_strlen(s));
    } else {
        arr[str_idx] = NULL;
    }

    return arr;
}

char **mx_strsplit(const char *s, char c) {
    if (!s) return NULL;
    char **arr = allocate_str_array(s, c);
    if (!arr) return NULL;
    return fill_str_array(arr, s, c);
}

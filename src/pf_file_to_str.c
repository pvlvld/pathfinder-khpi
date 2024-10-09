#include "../inc/pathfinder.h"
// Sheeeeeesh

static inline char *read_error(char *content) {
    if (content) {
        free(content);
        content = NULL;
    }
    return NULL;
}

static inline char *realloc_content(char *content, int total_size, char *buffer, size_t bytes_read) {
    char *temp = mx_realloc(content, total_size + bytes_read + 1);
    if (temp == NULL) return read_error(content);
    mx_memcpy(temp + total_size, buffer, bytes_read);
    return temp;
}

static inline int read_file(int fd, char **content) {
    char buffer[1024];
    int total_size = 0;
    int bytes_read;
    volatile bool overflow = false;
    while ((bytes_read = read(fd, buffer, 1024)) > 0) {
        *content = realloc_content(*content, total_size, buffer, bytes_read);
        if (*content == NULL) return -1;
        total_size += bytes_read;
        overflow = total_size < bytes_read;
        if (overflow) return -1;
    }

    return bytes_read == -1 ? -1 : total_size;
}

char *pf_file_to_str(const char *file, int *len) {
    if (file == NULL) return NULL;
    int fd = open(file, O_CLOEXEC | O_RDONLY);
    if (fd == -1) pf_error_exit(ENoFile, file, NULL, 0, 0, NULL);

    char *content = malloc((1) * sizeof(*content));
    content[0] = '\0';
    int bytes_read = read_file(fd, &content);
    if (bytes_read == -1) return read_error(content);
    if (bytes_read == 0) pf_error_exit(EFileEmpty, file, content, 0, 0, NULL);
    *len = bytes_read;
    return content;
}

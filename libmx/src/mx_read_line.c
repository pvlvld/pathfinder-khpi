#include "../inc/libmx.h"
#include <stdio.h>

static inline s_read_line_state *get_state(int fd, size_t buf_size) {
    static s_read_line_state state = {NULL, -1, 0, 0, 0};
    if (fd != state.fd) {
        state.buffer != NULL ? free(state.buffer) : (void)NULL;
        state.buffer = malloc(buf_size);
        state.fd = fd;
        state.buf_size = buf_size;
        state.buf_pos = 0;
        state.buf_len = 0;
    }

    return &state;
}

// static inline void free_state(s_read_line_state *state) {
//     if (state->buffer != NULL) {
//         free(state->buffer);
//         state->buffer = NULL;
//     }
// }

static inline int read_chunk(s_read_line_state *state) {
    ssize_t bytes_read = read(state->fd, state->buffer, state->buf_size);
    if (bytes_read <= 0) return bytes_read; // EOF || Error
    state->buf_pos = 0;
    state->buf_len = bytes_read;
    return 1;
}

static inline int process_chunk(s_read_line_state *state, char **line, size_t *line_len, char delim) {
    char *delim_pos = mx_strchr(state->buffer + state->buf_pos, delim);
    // Chuck length until delim
    size_t chunk_len = delim_pos ? delim_pos - (state->buffer + state->buf_pos) : state->buf_len - state->buf_pos;

    *line = mx_realloc(*line, *line_len + chunk_len + 1);
    if (!*line) return -2;

    mx_strncat(*line, state->buffer + state->buf_pos, chunk_len);
    *line_len += chunk_len;
    state->buf_pos += chunk_len;

    if (delim_pos) {
        state->buf_pos++;
        return 0; // Delimiter found
    }

    return 1; // Continue
}

static inline int handle_eof(char **line, size_t line_len, int status) {
    // printf("EOF\n");

    if (line_len == 0) {
        *line != NULL ? free(*line) : (void)NULL;
        return (status == 0) ? -1 : -2;
    }
    return line_len;
}

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd) {
    if (fd < 0 || !lineptr || buf_size <= 0) return -2;
    s_read_line_state *state = get_state(fd, buf_size);
    char *line = NULL;
    size_t line_len = 0;
    int status;

    while (1) {
        if (state->buf_pos >= state->buf_len) {
            status = read_chunk(state);
            if (status <= 0) return handle_eof(&line, line_len, status);
        }
        status = process_chunk(state, &line, &line_len, delim);
        if (status <= 0) break;
    }
    if (line) line[line_len] = '\0';
    *lineptr = line;

    return line_len;
}

int main(void) {
    int fd = open("matrix.txt", O_CLOEXEC | O_RDONLY);

    char *str = NULL;
    int bytes_writed = 0;
    // int l_counter = 0;
    while (bytes_writed > -1) {
        // l_counter++;
        bytes_writed = mx_read_line(&str, 18, '\n', fd);
        // printf("%d: %s\n", l_counter, str);
    }
    free(str);
    // fd = -69;
    // bytes_writed = mx_read_line(&str, 18, 'A', -69);
    // printf("Result: %d, Line: '%s'\n", bytes_writed, str); // -2
}

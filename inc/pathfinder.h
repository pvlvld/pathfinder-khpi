#pragma once

#define _POSIX_C_SOURCE 200809L
#define restrict __restrict__
#define SEPARATOR_LINE "========================================\n"

#include "../libmx/inc/libmx.h"
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <limits.h>
#include <malloc.h>
#include <errno.h>

typedef struct {
    int *path;
    int length;
    int distance;
} s_Path;

typedef struct {
    s_Path *paths;
    int count;
    int capacity;
} s_PathSet;

enum e_ErrCode { EInvalArg, ENoFile, EFileEmpty, EInvalLine, EInvalIslandCount, EDupBridge, ETotalCostOverflow };

void pf_print_int(int a, bool new_line);
void pf_print_str(const char *a, bool new_line, bool backward);
void pf_print_str_wrapper(const char *a, bool new_line);

#define pf_print(x, new_line) _Generic((x), \
    char*: pf_print_str_wrapper, \
    const char*: pf_print_str_wrapper, \
    int: pf_print_int \
)((x), (new_line))

#define pf_print_str_backward(x, nl) pf_print_str((x), (nl), true)

int pf_atoi(const char *str);
long long pf_memchridx(char *s, char c, size_t n, bool (*validator_fn)(char));
char *pf_file_to_str(const char *file, int *len);
char *pf_itoa_10(int value, char *buffer);
void pf_error_exit(enum e_ErrCode err, const char *filename, char *data, int line, int islands_count,void *all_paths);
bool pf_is_letter(char c);

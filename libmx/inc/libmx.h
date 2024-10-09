#pragma once

#define _POSIX_C_SOURCE 200809L
#define restrict __restrict__
#define BUFFER_SIZE_READ_FILE 2048
#define BUFFER_SIZE_READ_LINE 1024

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <fcntl.h>
#include <stddef.h>
#include <limits.h>
#include <malloc.h>
#include <errno.h>
#include <math.h>
#include <float.h>


// STRUCTS
typedef struct {
    char *buffer;
    int fd;
    size_t buf_size;
    size_t buf_pos;
    size_t buf_len;
} s_read_line_state;

typedef struct s_list {
  void *data;
  struct s_list *next;
} t_list;

// UTILS
void mx_printchar(char c); 
void mx_print_unicode(wchar_t c); 
void mx_printstr(const char *s); 
void mx_print_strarr(char **arr, const char *delim); 
void mx_printint(int n); 
double mx_pow(double n, unsigned int pow); 
int mx_sqrt(int x); 
char *mx_nbr_to_hex(size_t nbr); 
size_t mx_hex_to_nbr(const char *hex); 
char *mx_itoa(int number); 
void mx_foreach(int *arr, int size, void (*f)(int)); 
int mx_binary_search(char **arr, int size, const char *s, int *count);  
int mx_bubble_sort(char **arr, int size); 
int mx_quicksort(char **arr, int left, int right); 

// EXTRA UTILS
int mx_isspace(char c);
void mx_free_arr(void **arr, int length);
int max(int a, int b);
int min(int a, int b);
char *mx_strncat(char *restrict dst, const char *restrict src, size_t len);
char *mx_strchr(const char *s, int c);

// STRINGS
int mx_strlen(const char *s); 
void mx_swap_char(char *s1, char *s2); 
void mx_str_reverse(char *s); 
void mx_strdel(char **str); 
void mx_del_strarr(char ***arr); 
int mx_get_char_index(const char *str, char c); 
char *mx_strdup(const char *s1); 
char *mx_strndup(const char *s1, size_t n); 
char *mx_strcpy(char *dst, const char *src); 
char *mx_strncpy(char *dst, const char *src, int len); 
int mx_strcmp(const char *s1, const char *s2); 
char *mx_strcat(char *restrict s1, const char *restrict s2); 
char *mx_strstr(const char *haystack, const char *needle); 
int mx_get_substr_index(const char *str, const char *sub); 
int mx_count_substr(const char *str, const char *sub); 
int mx_count_words(const char *str, char c); 
char *mx_strnew(const int size); 
char *mx_strtrim(const char *str); 
char *mx_del_extra_spaces(const char *str); 
char **mx_strsplit(const char *s, char c); 
char *mx_strjoin(const char *s1, const char *s2); 
char *mx_file_to_str(const char *file); 
char *mx_replace_substr(const char *str, const char *sub, const char *replace); 
int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd); 

// EXTRA STRINGS
void mx_swap_strings(char **s1, char **s2);

// MEMORY
void *mx_memset(void *b, int c, size_t len); 
void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n); 
void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n); //
int mx_memcmp(const void *s1, const void *s2, size_t n); 
void *mx_memchr(const void *s, int c, size_t n); 
void *mx_memrchr(const void *s, int c, size_t n); 
void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len); 
void *mx_memmove(void *dst, const void *src, size_t len); 
void *mx_realloc(void *ptr, size_t size); 

// LINKED LIST
t_list *mx_create_node(void *data); 
void mx_push_front(t_list **list, void *data); 
void mx_push_back(t_list **list, void *data); 
void mx_pop_front(t_list **head); 
void mx_pop_back(t_list **head); 
int mx_list_size(t_list *list); 
t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *, void *)); 

// EXTRA LINKED LIST
t_list *mx_merge_sorted_lists(t_list *list1, t_list *list2, bool (*cmp)(void *, void *));
void mx_swap_list_data(t_list *a, t_list *b);
t_list *mx_merge_sort_list(t_list *lst, bool (*cmp)(void *, void *));

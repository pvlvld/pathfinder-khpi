#include "../inc/libmx.h"

void *mx_realloc(void *ptr, size_t new_size) {
    if (new_size == 0) {
        free(ptr);
        return NULL;
    }

    size_t current_size = malloc_usable_size(ptr);
    if (new_size <= current_size) return ptr;

    void *new_ptr = malloc(new_size);
    if (new_ptr == NULL) return NULL;

    if (ptr) {
        mx_memcpy(new_ptr, ptr, current_size);
        free(ptr);
    }

    return new_ptr;
}

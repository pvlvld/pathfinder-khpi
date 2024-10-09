#include "../inc/pathfinder.h"

long long pf_memchridx(char *s, char c, size_t n, bool (*validator_fn)(char)) {
    char *p = s;
    if (validator_fn == NULL) {
        for (size_t i = 0; i < n; i++, p++) {
            if (*p == c) return i;
        }
    } else {
        for (size_t i = 0; i < n; i++, p++) {
            if (*p == c) return i;
            if (!validator_fn(*p)) return -1;
        }
    }
    return -1;
}

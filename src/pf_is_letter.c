#include "../inc/pathfinder.h"

bool pf_is_letter(char c) {
    if (c > 64 && c < 91) return true;
    if (c > 96 && c < 123) return true;
    return false;
}

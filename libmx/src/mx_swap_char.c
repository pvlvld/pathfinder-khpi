void mx_swap_char(char *s1, char *s2) {
    if (s1 && s2) *s1 ^= *s2 ^= *s1 ^= *s2;
}

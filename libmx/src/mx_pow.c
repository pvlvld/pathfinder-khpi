#include "../inc/libmx.h"

double mx_pow(double n, unsigned int pow) {
    if ((n == 0.0 && pow < 0)) {
        errno = ERANGE;
        return HUGE_VAL;
    };

    if (pow == INFINITY || pow == -INFINITY) {
        if (pow > 0) return (n > 1) ? HUGE_VAL : (n == 1) ? 1.0 : 0.0;
        return (n > 1) ? 0.0 : (n == 1) ? 1.0 : HUGE_VAL;
    }

    double result = 1.0;
    for (int exp = pow < 0 ? -pow : pow; exp > 0; exp--) result *= n;

    if ((result > DBL_MAX) && (errno = ERANGE)) return result;

    if (pow < 0) result = 1.0 / result;

    return result;
}

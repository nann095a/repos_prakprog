#include "sfuns.h"
#include <cmath>
#include <algorithm>

namespace sfuns {

bool approx(double a, double b, double acc, double eps) {
    double diff = std::abs(a - b);
    if (diff <= acc) return true;

    double max_ab = std::max(std::abs(a), std::abs(b));
    return diff <= eps * max_ab;
}
float machine_epsilon_float() {
    float f = 1.0f;
    while ((float)(1.0f + f) != 1.0f) {
        f /= 2.0f;
    }
    return f * 2.0f;
}

double machine_epsilon_double() {
    double d = 1.0;
    while ((double)(1.0 + d) != 1.0) {
        d /= 2.0;
    }
    return d * 2.0;
}
long double machine_epsilon_long_double() {
    long double l = 1.0L;
    while ((long double)(1.0L + l) != 1.0L) {
        l /= 2.0L;
    }
    return l * 2.0L;
}
}
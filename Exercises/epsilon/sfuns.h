#pragma once

namespace sfuns {
bool approx(double a, double b,
            double acc = 1e-9,
            double eps = 1e-9);

float machine_epsilon_float();
double machine_epsilon_double();
long double machine_epsilon_long_double();
}
#include <iostream>
#include <limits>
#include <cmath>
#include <cstdio>
#include <iomanip>

#include "sfuns.h"

int main() {
    std::cout << "\n1:\n";
    float f = sfuns::machine_epsilon_float();
    double d = sfuns::machine_epsilon_double();
    long double l = sfuns::machine_epsilon_long_double();

    std::printf("Computed epsilons:\n");
    std::printf("float eps = %g\n", f);
    std::printf("double eps = %g\n", d);
    std::printf("long double eps = %Lg\n\n", l);

    std::cout << "From <limits>:\n";
    std::cout << std::numeric_limits<float>::epsilon() << "\n";
    std::cout << std::numeric_limits<double>::epsilon() << "\n";
    std::cout << std::numeric_limits<long double>::epsilon() << "\n\n";

    std::cout << "Theoretical:\n";
    std::cout << "float ~ 2^-23 = " << std::pow(2, -23) << "\n";
    std::cout << "double ~ 2^-52 = " << std::pow(2, -52) << "\n";
    std::cout << "long double ~ 2^-52 = " << std::pow(2, -52) << "\n\n";

    double d1 = 0.1 * 8;
    double d2 = 0.1+0.1+0.1+0.1+0.1+0.1+0.1+0.1;

    std::cout << "d1 == d2 (==)       : " << (d1 == d2) << "\n";
    std::cout << "d1 approx d2        : " << sfuns::approx(d1, d2) << "\n";

    // 2
    std::cout << "\n2:\n";
    std::cout << "\nNon-commutativity:\n";

    double epsilon = std::pow(2.0, -52);
    double tiny = epsilon / 2.0;

    double a = 1.0 + tiny + tiny;
    double b = tiny + tiny + 1.0;

    std::cout << "a == b ? " << (a == b ? "true" : "false") << "\n";
    std::cout << "a > 1  ? " << (a > 1  ? "true" : "false") << "\n";
    std::cout << "b > 1  ? " << (b > 1  ? "true" : "false") << "\n";

    std::cout << std::fixed << std::setprecision(17);

    std::cout << "tiny = " << tiny << "\n";
    std::cout << "1 + tiny + tiny = " << a << "\n";
    std::cout << "tiny + tiny + 1 = " << b << "\n";   

    // 3
    std::cout << "\n3:\n";
    double d1_1 = 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1;
    double d2_1 = 8 * 0.1;

    std::cout << "\nComparing doubles:\n";

    std::cout << std::fixed << std::setprecision(17);
    std::cout << "d1 = " << d1_1 << "\n";
    std::cout << "d2 = " << d2_1 << "\n";

    // direct comparison (wrrong)
    std::cout << "d1 == d2 ? " << (d1_1 == d2_1 ? "true" : "false") << "\n";

    // 4
    std::cout << "\n4:\n\n";

    // approx comparison (correct)
    std::cout << "approx(d1, d2) ? " 
        << (sfuns::approx(d1_1, d2_1) ? "true" : "false") << "\n";

    return 0;
}
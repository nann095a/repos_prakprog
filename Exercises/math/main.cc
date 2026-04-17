#include <iostream>
#include <cmath>
#include <complex>
#include <iomanip>
#include "sfuns.h"

using Complex = std::complex<double>;

constexpr double PI = 3.14159265358979323846;
constexpr double E  = 2.71828182845904523536;
const Complex I(0.0,1.0);

int main()
{
    std::cout << std::setprecision(6);

    std::cout << "sqrt(2) = " << std::sqrt(2.0) << "\n";
    std::cout << "21/5 = " << 21.0/5.0 << "\n";
    std::cout << "e^pi = " << std::pow(E, PI) << "\n";
    std::cout << "e^i = " << std::pow(E, I) << "\n";
    std::cout << "pi^e = " << std::pow(PI, E) << "\n";
    std::cout << "pi^i = " << std::pow(PI, I) << "\n";
    std::cout << "i^i = " << std::pow(I, I) << "\n";
    std::cout << "log(i) = " << std::log(I) << "\n";

    std::cout << "\nfGamma function:\n";
    for(int n = 1; n <= 10; n++) {
        std::cout << "Gamma(" << n << ") = " << sfuns::fgamma(n) << "\n";
    }
    std::cout << "\nlnGamma function:\n";
    for(int n = 1; n <= 10; n++) {
        std::cout << "lnGamma(" << n << ") = " << sfuns::lngamma(n) << "\n";
    }

std::cout << "\nCheck\n";
for(int n = 1; n <= 10; n++) {
    std::cout << "exp(lnGamma(" << n << ")) = " << std::exp(sfuns::lngamma(n)) << "\n";
}

std::cout << "\nError check:\n";
for(int n = 1; n <= 10; n++) {
    double gamma_fg = sfuns::fgamma(n);
    double gamma_lg = std::exp(sfuns::lngamma(n));

    std::cout << "n = " << n
              << " error = "
              << std::abs(gamma_lg - gamma_fg)
              << "\n";
}

    return 0;
}
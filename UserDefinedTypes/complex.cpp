#include "complex.h"

#include <iostream>
#include <cmath>
#include <complex>

namespace mycode {
    int main() {
        complex z {9, 0};
        auto z2 = my_sqrt(z);

        std:: cout << "sqrt(" << z.real() << ", " << z.imag() << ") = " << '(' << z2.real() << ", " << z2.imag() << "i)\n";
        // ...

        return 0;
    }

    complex my_sqrt(const complex z) {
        if (z.imag() == 0) {
            return complex(sqrt(z.real()));
        }

        double zAbs = sqrt(z.real() * z.real() + z.imag() * z.imag());
        return complex(sqrt((zAbs + z.real()) / 2), z.imag() / abs(z.imag()) * sqrt((zAbs - z.real()) / 2));
    }

    complex& complex::operator*=(const complex& c) {
        re = re * c.re - im * c.im;
        im = re * c.im + im * c.re;
        return *this;
    }

    complex& complex::operator/=(const complex& c) {
        double denominator = c.re * c.re + c.im * c.im;
        re = (re * c.re + im * c.im) / denominator;
        im = (im * c.re - re * c.im) / denominator;
        return *this;
    }
}


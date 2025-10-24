//
// Created by csabi on 23/10/2025.
//

#ifndef USERDEFINEDTYPES_COMPLEX_H
#define USERDEFINEDTYPES_COMPLEX_H

namespace mycode {
    class complex {
    private:
        double re;
        double im;
    public:
        complex(double r, double i) :re{r}, im{i} {}
        explicit complex(double r) :re{r}, im{0} {}
        complex() :re{0}, im{0} {}
        void real(const double r) {re = r;}
        [[nodiscard]] double real() const {return re;}
        void imag(const double i) {im = i;}
        [[nodiscard]] double imag() const {return im;}

        complex& operator+=(const complex& c) {re += c.re; im += c.im; return *this;}
        complex& operator-=(const complex& c) {re -= c.re; im -= c.im; return *this;}
        complex& operator*=(const complex& c);
        complex& operator/=(const complex& c);
    };

    complex my_sqrt(complex);
    // ...
    int main();
}

#endif //USERDEFINEDTYPES_COMPLEX_H
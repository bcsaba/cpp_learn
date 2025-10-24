#include "vector.h"

#include <initializer_list>

Vector::Vector(int s)
    :elem(elem = new double[s]), sz(s) {
    for (int i = 0; i != sz; ++i) {
        elem[i] = 0;
    }
}

Vector::Vector(std::initializer_list<double> l)
    :elem(elem = new double[l.size()]), sz(l.size()) {
    int i = 0;
    for (auto e : l) {
        elem[i++] = e;
    }
}

double& Vector::operator[] (const int i) const {
    return elem[i];
}

int Vector::size() const {
    return sz;
}

Vector::~Vector() {
    delete[] elem;
}

//
// Created by csabi on 26/09/2025.
//

#ifndef USERDEFINEDTYPES_VECTOR_H
#define USERDEFINEDTYPES_VECTOR_H

#include <initializer_list>

class Vector {
    double* elem;
    int sz;
public:
    explicit Vector(int s);
    Vector(std::initializer_list<double>);
    double& operator[](int i) const;
    [[nodiscard]] int size() const;
    void push_back(double element);
    ~Vector();
};

#endif //USERDEFINEDTYPES_VECTOR_H
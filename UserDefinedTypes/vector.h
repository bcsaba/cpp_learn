//
// Created by csabi on 26/09/2025.
//

#ifndef USERDEFINEDTYPES_VECTOR_H
#define USERDEFINEDTYPES_VECTOR_H

class Vector {
    double* elem;
    int sz;
public:
    explicit Vector(int s);
    double& operator[](int i);
    int size();
};

#endif //USERDEFINEDTYPES_VECTOR_H
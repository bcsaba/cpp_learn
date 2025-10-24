//
// Created by csabi on 26/09/2025.
//

#ifndef USERDEFINEDTYPES_VECTOR_H
#define USERDEFINEDTYPES_VECTOR_H

class Vector {
public:
    Vector(int s);
    double& operator[](int i);
    int size();
private:
    double* elem;
    int sz;
};

#endif //USERDEFINEDTYPES_VECTOR_H
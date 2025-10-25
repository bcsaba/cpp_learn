//
// Created by csabi on 25/10/2025.
//

#ifndef USERDEFINEDTYPES_VECTOR_CONTAINER_H
#define USERDEFINEDTYPES_VECTOR_CONTAINER_H
#include "container.h"
#include "vector.h"

namespace mycode {
    class Vector_container : public Container {
        Vector v;

    public:
        explicit Vector_container(int s) : v(s) {}
        explicit Vector_container(std::initializer_list<double> li) : v(li) {}
        ~Vector_container() override = default;

        double operator[](const int i) override { return v[i]; }
        [[nodiscard]] unsigned long size() const override { return v.size(); }
    };
}

#endif //USERDEFINEDTYPES_VECTOR_CONTAINER_H
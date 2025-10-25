//
// Created by csabi on 25/10/2025.
//

#ifndef USERDEFINEDTYPES_LIST_CONTAINER_H
#define USERDEFINEDTYPES_LIST_CONTAINER_H
#include <list>

#include "container.h"

namespace mycode {
    class List_Container : public Container {
        std::list<double> ld;
    public:
        explicit List_Container()  {}; // empty list
        List_Container(const std::initializer_list<double> li) : ld{li} { }
        ~List_Container() override = default;

        double operator[](int i) override;
        [[nodiscard]] unsigned long size() const override { return ld.size(); };
    };
}

#endif //USERDEFINEDTYPES_LIST_CONTAINER_H
//
// Created by csabi on 24/10/2025.
//

#ifndef USERDEFINEDTYPES_CONTAINER_H
#define USERDEFINEDTYPES_CONTAINER_H

namespace mycode {
    class Container {
    public:
        virtual double operator[](int) = 0;
        [[nodiscard]] virtual unsigned long size() const = 0;
        virtual ~Container() = default;
    };
}

#endif //USERDEFINEDTYPES_CONTAINER_H
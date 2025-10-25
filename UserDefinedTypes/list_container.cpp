//
// Created by csabi on 25/10/2025.
//

#include "list_container.h"

#include <stdexcept>

namespace mycode {
    double List_Container::operator[](int i) {
        for (auto& x : ld) {
            if (i == 0) {
                return x;
            }

            i--;
        }
        throw std::out_of_range("Index out of range: List container");
    }
}

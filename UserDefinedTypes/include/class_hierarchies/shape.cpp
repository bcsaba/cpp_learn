//
// Created by csabi on 25/10/2025.
//

#include "./shape.h"

namespace shapes {
    void Circle::draw() const {
        std::cout << "Circle draw ..." << std::endl;
    }

    void Smiley::draw() const {
        std::cout << "Smiley draw ..." << std::endl;

        Circle::draw();
        // for (auto& eye : eyes) {
        //     eye->draw();
        // }
        // mouth->draw();
    }

    Smiley::~Smiley() {
    }
}

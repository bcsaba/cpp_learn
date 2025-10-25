//
// Created by csabi on 25/10/2025.
//

#ifndef USERDEFINEDTYPES_SHAPE_H
#define USERDEFINEDTYPES_SHAPE_H
#include <format>
#include <iostream>
#include <ostream>
#include <vector>

namespace shapes {
    class Point {
        double x;
        double y;
    public:
        Point(const double x, const double y) : x(x), y(y) { }

        friend std::ostream& operator<<(std::ostream& os, const Point& p) {
            return os << std::format("({}, {})", p.x, p.y);
        };
    };

    class Shape {
    public:
        [[nodiscard]] virtual Point center() const = 0;
        virtual void move(Point to) = 0;

        virtual void draw() const= 0;
        virtual void rotate(float angle) const = 0;

        virtual ~Shape() = default;
    };

    class Circle : public Shape {
    protected:
        Point centerPoint;

    public:
        double radius;
        Circle(Point center, double radius) : centerPoint(center), radius(radius) {  }

        [[nodiscard]] Point center() const override { return centerPoint; }

        void move(const Point to) override {
            centerPoint = to;
            std::cout << "Circle moved to: " << to << std::endl;
        }
        virtual void draw() const override { std::cout << "Circle draw ..." << std::endl; }

        void rotate(float angle) const override { std::cout << "Circle rotate with angle" << angle <<"..." << std::endl; };
    };

    class Smiley : public Circle {
        std::vector<Shape*> eyes;
        Shape* mouth;

    public:
        Smiley(Point center, double radius, Shape* mouth, const std::vector<Shape*>& eyes)
            : Circle{center, radius}, mouth(mouth), eyes(eyes) { }

        // centerPoint(center), radius(radius), eyes(eyes), mouth(mouth)  {  }

        void move(const Point to) override {

            std::cout << "Smiley moved to: " << to << std::endl;
        };

        void draw() const override {std::cout << "Smiley draw ..." << std::endl;}

        inline void rotate(float angle) const override { std::cout << "Smiley rotate with angle" << angle <<"..." << std::endl; };

        ~Smiley() override;
    };


    inline void rotate_all(std::vector<Shape*>& shapes, float angle) {
        for (const auto shape: shapes) {
            shape->rotate(angle);
        }
    }
}


#endif //USERDEFINEDTYPES_SHAPE_H
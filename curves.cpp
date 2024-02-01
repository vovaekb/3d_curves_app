#include <cmath>
#include <iostream>
#include "curves.h"

#define PI 3.14159265

using namespace std;

Shape::Shape() {}
void Shape::print() {}
Point Shape::getPoint(float t) {}
Vector Shape::getDerivative(float t) {}

Circle::Circle(Point p, float rad) : center(p), radius(rad) {}
Circle::Circle(const Circle& other) {
    center = other.center;
    radius = other.radius;
}
float Circle::getRadius()
{
    return radius;
}
void Circle::print()
{
    cout << "Circle" << endl;
    cout << radius << ", " << endl;
    center.print();
}
Point Circle::getPoint(float t) {
    auto x = center.getX() + radius * cos(t);
    auto y = center.getY() + radius * sin(t);
    auto z = 0;
    Point p (x, y, z);
    return p;
}
Vector Circle::getDerivative(float t) {
    auto x = radius * (-1) * sin(t);
    auto y = radius * cos(t);
    auto z = 0;
    Vector p (x, y, z);
    return p;
}

Ellipse::Ellipse(Point p, float rad_x, float rad_y) : center(p), radius_x(rad_x), radius_y(rad_y) {}
Ellipse::Ellipse(const Ellipse& other) {
    center = other.center;
    radius_x = other.radius_x;
    radius_y = other.radius_y;
}
void Ellipse::print()
{
    cout << "Ellipse" << endl;
    cout << radius_x << ", " << radius_y << ", " << endl;
    center.print();
}
Point Ellipse::getPoint(float t) {
    auto x = center.getX() + radius_x * cos(t);
    auto y = center.getY() + radius_y * sin(t);
    auto z = 0;
    Point p (x, y, z);
    return p;
}
Vector Ellipse::getDerivative(float t) {
    auto x = radius_x * (-1) * sin(t);
    auto y = radius_y * cos(t);
    auto z = 0;
    Vector p (x, y, z);
    return p;
}

Helix::Helix(Point p, float rad, float step) : center(p), radius(rad), step_(step) {}
Helix::Helix(const Helix& other) {
    center = other.center;
    radius = other.radius;
    step_ = other.step_;
}
void Helix::print()
{
    cout << "Helix" << endl;
    cout << radius << ", " << step_ << endl;
    center.print();
}
Point Helix::getPoint(float t) {
    auto x = center.getX() + radius * cos(t);
    auto y = center.getY() + radius * sin(t);
    decltype(x) z = step_ * t / (2 * PI);
    Point p (x, y, z);
    return p;
}
Vector Helix::getDerivative(float t) {
    auto x = radius * (-1) * sin(t);
    auto y = radius * cos(t);
    decltype(x) z = step_ / (2 * PI);
    Vector p (x, y, z);
    return p;
}
#include <cmath>
#include <iostream>
#include "curves.h"

#define PI 3.14159265

using namespace std;

Shape::Shape() {}
Point Shape::getPoint(float t) {}
Vector Shape::getDerivative(float t) {}

Circle::Circle(Point p, int rad) : center(p), radius(rad) {
    cout << "Circle::Circle" << endl;
}
Point Circle::getPoint(float t) {
    int x = center.getX() + radius * cos(t);
    int y = center.getY() + radius * sin(t);
    int z = 0;
    Point p (x, y, z);
    return p;
}
Vector Circle::getDerivative(float t) {
    int x = radius * (-1) * sin(t);
    int y = radius * cos(t);
    int z = 0;
    Vector p (x, y, z);
    return p;
}

Ellipse::Ellipse(Point p, int rad_x, int rad_y) : center(p), radius_x(rad_x), radius_y(rad_y) {}
Point Ellipse::getPoint(float t) {
    int x = center.getX() + radius_x * cos(t);
    int y = center.getY() + radius_y * sin(t);
    int z = 0;
    Point p (x, y, z);
    return p;
}
Vector Ellipse::getDerivative(float t) {
    int x = radius_x * (-1) * sin(t);
    int y = radius_y * cos(t);
    int z = 0;
    Vector p (x, y, z);
    return p;
}

Helix::Helix(Point p, int rad, int step) : center(p), radius(rad), step_(step) {}
Point Helix::getPoint(float t) {
    int x = center.getX() + radius * cos(t);
    int y = center.getY() + radius * sin(t);
    int z = step_ * t / (2 * PI);
    Point p (x, y, z);
    return p;
}
Vector Helix::getDerivative(float t) {
    int x = radius * (-1) * sin(t);
    int y = radius * cos(t);
    int z = step_ / (2 * PI);
    Vector p (x, y, z);
    return p;
}
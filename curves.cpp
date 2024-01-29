#include <cmath>
#include "curves.h"

#define PI 3.14159265

Shape::Shape() {}
Point Shape::getPoint(float t) {}
Vector Shape::getDerivative(float t) {}

Circle::Circle(Point p, int rad) : center(p), radius(rad) {}
Point Circle::getPoint(float t) {}
Vector Circle::getDerivative(float t) {}

Ellipse::Ellipse(Point p, int rad_x, int rad_y) : radius_x(rad_x), radius_y(rad_y) {}
Point Ellipse::getPoint(float t) {}
Vector Ellipse::getDerivative(float t) {}

Helix::Helix(int rad, int step) : radius(rad), step_(step) {}
Point Helix::getPoint(float t) {}
Vector Helix::getDerivative(float t) {}
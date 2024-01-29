#include <cmath>
#include "curves.h"

#define PI 3.14159265

Shape::Shape() {}
Point Shape::getPoint(float t) {}
Vector Shape::getDerivative(float t) {}

Circle::Circle(Point p, int rad) {}

Point Circle::getPoint(float t) {}
Vector Circle::getDerivative(float t) {}

Point Ellipse::getPoint(float t) {}
Vector Ellipse::getDerivative(float t) {}

Point Helix::getPoint(float t) {}
Vector Helix::getDerivative(float t) {}
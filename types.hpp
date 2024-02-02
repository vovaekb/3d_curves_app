#ifndef CADEX_TASK_TYPES_H
#define CADEX_TASK_TYPES_H

#include <iostream>

using namespace std;

/*!
  \class Point
  \brief Class representing 3D point in curve
*/
class Point
{
public:
    Point() = default;
    Point(float x, float y, float z) : x_(x), y_(y), z_(z) {}
    void print() { cout << x_ << ", " << y_ << ", " << z_ << endl; }
    float getX() const { return x_; }
    float getY() const { return y_; }
    float getZ() const { return z_; }
private:
    float x_;
    float y_;
    float z_;
};

/*!
  \class Vector
  \brief Class representing 3D vector
*/
class Vector
{
public:
    Vector() = default;
    Vector(float x, float y, float z) : x_(x), y_(y), z_(z) {}
    void print() { cout << x_ << ", " << y_ << ", " << z_ << endl; }
private:
    float x_;
    float y_;
    float z_;
};

#endif //CADEX_TASK_TYPES_H

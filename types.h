#ifndef CADEX_TASK_TYPES_H
#define CADEX_TASK_TYPES_H

#include <iostream>

using namespace std;

class Point
{
public:
    Point() = default;
    Point(int x, int y, int z) : x_(x), y_(y), z_(z) {}
    void print() { cout << x_ << ", " << y_ << ", " << z_ << endl; }
    int getX() const { return x_; }
    int getY() const { return y_; }
    int getZ() const { return z_; }
private:
    int x_;
    int y_;
    int z_;
};

class Vector
{
public:
    Vector() = default;
    Vector(int x, int y, int z) : x_(x), y_(y), z_(z) {}
    void print() { cout << x_ << ", " << y_ << ", " << z_ << endl; }
private:
    int x_;
    int y_;
    int z_;
};

#endif //CADEX_TASK_TYPES_H

#ifndef CADEX_TASK_TYPES_H
#define CADEX_TASK_TYPES_H


class Point
{
public:
    Point() = default;
    Point(int x, int y, int z) : x_(x), y_(y), z_(z) {}
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
private:
    int x_;
    int y_;
    int z_;
};

#endif //CADEX_TASK_TYPES_H

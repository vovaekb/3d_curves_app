#ifndef CADEX_TASK_TYPES_H
#define CADEX_TASK_TYPES_H


class Point
{
public:
    Point() = default;
    Point(int x, int y, int z) {}
private:
    int x_;
    int y_;
    int z_;
};

class Vector
{
public:
    Vector(int x, int y, int z) {}
private:
    int x;
    int y;
    int z;
};

#endif //CADEX_TASK_TYPES_H

#ifndef CADEX_TASK_CURVES_H
#define CADEX_TASK_CURVES_H

#include "types.h"

class Shape
{
public:
    Shape();
    virtual Point getPoint(float t);
    virtual Vector getDerivative(float t);
private:
};

class Circle : public Shape
{
public:
    Circle(Point p, int rad);
    Point getPoint(float t) override;
    Vector getDerivative(float t) override;
private:
    Point center;
    int radius;
};

class Ellipse : public Shape
{
public:
    Ellipse(Point p, int rad_x, int rad_y);
    Point getPoint(float t) override;
    Vector getDerivative(float t) override;
private:
    Point center;
    int radius_x;
    int radius_y;
};

class Helix : public Shape
{
public:
    Helix(Point p, int rad, int step);
    Point getPoint(float t) override;
    Vector getDerivative(float t) override;
private:
    Point center;
    int radius;
    int step_;
};

#endif //CADEX_TASK_CURVES_H

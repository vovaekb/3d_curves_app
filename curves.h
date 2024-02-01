#ifndef CADEX_TASK_CURVES_H
#define CADEX_TASK_CURVES_H

#include "types.h"

class Shape
{
public:
    Shape();
    virtual void print();
    virtual Point getPoint(float t);
    virtual Vector getDerivative(float t);
private:
};

class Circle : public Shape
{
public:
    Circle(Point p, float rad);
    void print();
    float getRadius();
    Point getPoint(float t) override;
    Vector getDerivative(float t) override;
private:
    Point center;
    float radius;
};

class Ellipse : public Shape
{
public:
    Ellipse(Point p, float rad_x, float rad_y);
    void print();
    Point getPoint(float t) override;
    Vector getDerivative(float t) override;
private:
    Point center;
    float radius_x;
    float radius_y;
};

class Helix : public Shape
{
public:
    Helix(Point p, float rad, float step);
    void print();
    Point getPoint(float t) override;
    Vector getDerivative(float t) override;
private:
    Point center;
    float radius;
    float step_;
};

#endif //CADEX_TASK_CURVES_H

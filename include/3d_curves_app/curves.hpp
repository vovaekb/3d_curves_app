#ifndef CADEX_TASK_CURVES_H
#define CADEX_TASK_CURVES_H

#include "types.hpp"

class Shape
{
public:
    Shape();
    virtual void print();
    virtual Point getPoint(float t) const;
    virtual Vector getDerivative(float t) const;
};

class Circle : public Shape
{
public:
    Circle(Point p, float rad);
    Circle(const Circle& other);
    void print();
    float getRadius() const;
    Point getPoint(float t) const override;
    Vector getDerivative(float t) const override;
private:
    Point center;
    float radius;
};

class Ellipse : public Shape
{
public:
    Ellipse(Point p, float rad_x, float rad_y);
    Ellipse(const Ellipse& other);
    void print();
    Point getPoint(float t) const override;
    Vector getDerivative(float t) const override;
private:
    Point center;
    float radius_x;
    float radius_y;
};

class Helix : public Shape
{
public:
    Helix(Point p, float rad, float step);
    Helix(const Helix& other);
    void print();
    Point getPoint(float t) const override;
    Vector getDerivative(float t) const override;
private:
    Point center;
    float radius;
    float step_;
};

#endif //CADEX_TASK_CURVES_H

#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>
#include <memory>
#include <omp.h>
#include "types.hpp"
#include "curves.hpp"

const float PI = 3.14159265;

using namespace std;

using ShapePtr = std::shared_ptr<Shape>;

vector<ShapePtr> createCurvesList() {
    vector<ShapePtr> result;
    auto curves_number = 15;
    result.reserve(curves_number);
    for (auto i = 0; i < curves_number; i++)
    {
        int random_number = rand() % 3;
        auto x = rand() % 10;
        auto y = rand() % 10;
        auto z = rand() % 10;
        Point p (x, y, z);

        ShapePtr c;
        if (random_number == 0)
        {
            cout << "Create circle" << endl;
            auto radius = rand() % 10;
            c = std::make_shared<Circle>(p, radius);
        } else if (random_number == 1) {
            auto radius_x = rand() % 10;
            auto radius_y = rand() % 10;
            c = std::make_shared<Ellipse>(p, radius_x, radius_y);
        } else {
            auto radius = rand() % 10;
            auto step = rand() % 10;
            c = std::make_shared<Helix>(p, radius, step);
        }
        result.emplace_back(c);
    }
    return result;
}

void printCurvesCoords(const vector<ShapePtr> &v) {
    auto t = PI / 4;
    for(const auto &c: v)
    {
        Point res = c->getPoint(t);
        res.print();
        Vector der = c->getDerivative(t);
        der.print();
        cout << endl;
    }
}

vector<ShapePtr> createSecondList(vector<ShapePtr> &v) {
    vector<ShapePtr> second_list;
    std::copy_if(v.begin(),
                 v.end(),
                 std::back_inserter(second_list),
                 [](auto &c) {
                     return (dynamic_cast<Circle*>(c.get()) != nullptr);
                 });
    for(const auto &c: second_list)
    {
        c->print();
        cout << endl;
    }
    return second_list;
}

bool sortByRadius (const ShapePtr &c1, const ShapePtr &c2) {
    auto circle_1 = dynamic_cast<Circle*>(c1.get());
    auto circle_2 = dynamic_cast<Circle*>(c2.get());
    return (
        circle_1->getRadius() < circle_2->getRadius()
    );
}

void sortSecondList(vector<ShapePtr> &v) {
    std::sort(v.begin(),
        v.end(),
        sortByRadius);
}

float getCurvesRadiiSum(vector<ShapePtr> &v) {
    auto result = 0;
    #pragma omp parallel for reduction( +: result )
    for(const auto &c: v)
    {
        result += dynamic_cast<Circle*>(c.get())->getRadius();
    }
    return result;
}

int main() {
    auto curves_list = createCurvesList();
    printCurvesCoords(curves_list);
    auto circles_list =
        createSecondList(curves_list);
    sortSecondList(circles_list);
    auto radii_sum = getCurvesRadiiSum(circles_list);
    cout << "Total radii sum: " << radii_sum << endl;

    return 0;
}



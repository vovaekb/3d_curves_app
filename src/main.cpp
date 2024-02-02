#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <vector>
#include <memory>
#include <omp.h>
#include "3d_curves_app/types.hpp"
#include "3d_curves_app/curves.hpp"

const float PI = 3.14159265;
const int CURVES_NUMBER = 15;

using namespace std;

using ShapePtr = std::shared_ptr<Shape>;

/**
 * Create list of curves.
 *
 * @return list of curves
 *
 */
vector<ShapePtr> createCurvesList() {
    srand(time(0));
    vector<ShapePtr> result;
    result.reserve(CURVES_NUMBER);
    for (auto i = 0; i < CURVES_NUMBER; i++)
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

/**
 * Create list of curves.
 *
** @param v the list of curves. Must be either absolute or relative to
 *
 */
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

/**
 * Create a second container populating with circles from the first container.
 *
** @param v the list of curves
 *
 * @return list of curves
 *
 */
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

/**
 * Method for comparing two circle objects based on radius.
 *
 * @param c1 the shared_ptr on the first circle object to compare. Passed by const reference
*
 * @param c1 the shared_ptr on the first circle object to second. Passed by const reference
 *
 * @return the result of comparison
 */
bool sortByRadius (const ShapePtr &c1, const ShapePtr &c2) {
    auto circle_1 = dynamic_cast<Circle*>(c1.get());
    auto circle_2 = dynamic_cast<Circle*>(c2.get());
    return (
        circle_1->getRadius() < circle_2->getRadius()
    );
}

/**
 * Sorts second list of curves by radii.
 *
 * @param v the list of curves
 *
 */
void sortSecondList(vector<ShapePtr> &v) {
    std::sort(v.begin(),
        v.end(),
        sortByRadius);
}

/**
 * Computes the total sum of radii of all curves in the second container
 *
** @param v the list of curves
 *
 * @return total sum of radii of all curves
 *
 */
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



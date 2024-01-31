#include <cstdlib>
#include <iostream>
#include <vector>
#include <memory>
#include "types.h"
#include "curves.h"

#define PI 3.14159265

using namespace std;

vector<std::shared_ptr<Shape> > createCurvesList() {
    vector<std::shared_ptr<Shape> > result;
    auto curves_number = 15;
    result.reserve(curves_number);
    for (auto i = 0; i < curves_number; i++)
    {
        int random_number = rand() % 3;
        auto x = rand() % 10;
        auto y = rand() % 10;
        auto z = rand() % 10;
        Point p (x, y, z);

        std::shared_ptr<Shape> c;
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
    // Examine curves
    for(const auto &c: result)
    {
        c->print();
        cout << endl;
    }
    return result;
}

void printCurvesCoords() {}

void printCurvesDerivatives() {}

int getCurvesRadiiSum() {}

int main() {
    auto curves_list = createCurvesList();

    return 0;
}



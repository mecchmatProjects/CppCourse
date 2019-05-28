#pragma once

#include "common.hpp"

class Point
{
private:
    double x, y;

public:
    Point();
    Point(double x, double y);
    ~Point();
    double GetX();
    double GetY();
};

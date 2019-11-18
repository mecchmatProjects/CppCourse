#pragma once

#include "vector"

#include "common.hpp"
#include "Point.hpp"

class Furniture
{
private:
    std::vector<Point> points;

public:
    Furniture();
    ~Furniture();
    std::vector<Point> GetPoints();
};

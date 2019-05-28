#include "Furniture.hpp"

#include <iostream>

Furniture::Furniture()
{
    uint pointsCount;
    double x, y;

    std::cout << "\nFurniture:";
    for (size_t i = 0; i < pointsCount; i++)
    {
        std::cout << "\nPoint " << i << ":\n";
        std::cout << "Input x y:\n";
        std::cin >> x >> y;
        Point point = Point(x, y);
        this->points.push_back(point);
    }
}

Furniture::~Furniture()
{
}

std::vector<Point> Furniture::GetPoints()
{
    return this->points;
}
#include "Wall.hpp"

#include <iostream>

Wall::Wall()
{
    double x1, y1, x2, y2;
    std::cout << "\nWall:\n";
    std::cout << "Input x1 y1:\n";
    std::cin >> x1 >> y1;
    std::cout << "\nInput x2 y2:\n";
    std::cin >> x2 >> y2;
    this->p1 = Point(x1, y1);
    this->p2 = Point(x2, y2);
}

Wall::~Wall()
{
}

Point Wall::GetP1()
{
    return this->p1;
}

Point Wall::GetP2()
{
    return this->p2;
}
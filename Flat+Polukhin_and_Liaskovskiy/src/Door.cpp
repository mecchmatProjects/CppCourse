#include "Door.hpp"
#include "Point.hpp"

#include <iostream>

Door::Door()
{
    double x1, y1, x2, y2;
    std::cout << "\nDoor:\n";
    std::cout << "Input x1 y1:\n";
    std::cin >> x1 >> y1;
    std::cout << "Input x2 y2:\n";
    std::cin >> x2 >> y2;
    this->p1 = Point(x1, y1);
    this->p2 = Point(x2, y2);
}

Door::~Door()
{
}

Point Door::GetP1()
{
    return this->p1;
}

Point Door::GetP2()
{
    return this->p2;
}
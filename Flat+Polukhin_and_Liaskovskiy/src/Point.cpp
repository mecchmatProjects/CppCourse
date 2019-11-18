#include "Point.hpp"

Point::Point()
{
}

Point::Point(double x, double y)
{
    this->x = x;
    this->y = y;
}

Point::~Point()
{
}

double Point::GetX() { return this->x; }
double Point::GetY() { return this->y; }

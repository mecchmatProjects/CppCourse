#pragma once

#include "common.hpp"
#include "Point.hpp"
#include "Apartment.hpp"

#include <iostream>

class Target
{
private:
    Point point;
    uint apartment;
    TargetType targetType;

public:
    Target();
    Target(Point point);
    Target(uint apartment);
    ~Target();
    TargetType GetType();
    uint GetApartmentID();
    Point GetPoint();
};
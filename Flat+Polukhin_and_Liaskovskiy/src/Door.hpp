#pragma once

#include "common.hpp"
#include "Point.hpp"

class Door
{
private:
    Point p1, p2;

public:
    Door();
    ~Door();
    Point GetP1();
    Point GetP2();
};
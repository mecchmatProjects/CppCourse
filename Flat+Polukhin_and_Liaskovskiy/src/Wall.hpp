#pragma once

#include "common.hpp"
#include "Point.hpp"

class Wall
{
private:
    Point p1, p2;

public:
    Wall();
    ~Wall();
    Point GetP1();
    Point GetP2();
};
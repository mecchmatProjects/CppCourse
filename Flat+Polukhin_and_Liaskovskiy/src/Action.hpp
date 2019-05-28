#pragma once

#include "common.hpp"

class Action
{
private:
    double distance, angle;

public:
    Action();
    Action(double distance, double angle);
    ~Action();
    double GetDistance();
    double GetAngle();
};
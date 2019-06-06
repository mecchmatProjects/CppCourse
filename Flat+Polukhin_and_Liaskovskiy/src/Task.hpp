#pragma once

#include <iostream>
#include <vector>

#include "common.hpp"
#include "Robot.hpp"
#include "Flat.hpp"
#include "Target.hpp"

class Task
{
private:
    Flat flat;
    Target target;
    std::vector<Robot> robots;
    std::vector<uint> results;

public:
    Task();
    ~Task();
    void DoTest();
    uint GetAverageScore();
};
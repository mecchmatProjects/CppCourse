#pragma once

#include <iostream>
#include <vector>

#include "common.hpp"
#include "Action.hpp"

class Way
{
private:
    std::vector<Action> actions;

public:
    Way();
    ~Way();
    Action GetAction(uint i);
    std::vector<Action> GetActions();
    void AddAction(Action action);
};
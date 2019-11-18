#include "Way.hpp"

#include <iostream>

Way::Way()
{
}

Way::~Way()
{
}

std::vector<Action> Way::GetActions()
{
    return this->actions;
}

Action Way::GetAction(uint i)
{
    return this->actions[i];
}

void Way::AddAction(Action action)
{
    this->actions.push_back(action);
}
#include "Action.hpp"

Action::Action(){
    this->distance = 0;
    this->angle = 0;
}

Action::Action(double distance, double angle)
{
    this->distance = distance;
    this->angle = angle;
}

Action::~Action()
{
}

double Action::GetDistance(){
    return this->distance;
}

double Action::GetAngle(){
    return this->angle;
}
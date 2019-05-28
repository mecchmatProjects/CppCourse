#include "Target.hpp"
#include "Point.hpp"

Target::Target()
{
}

Target::Target(Point point)
{
    this->point = point;
    this->targetType = POINT;
}

Target::Target(uint apartment)
{
    this->apartment = apartment;
    this->targetType = APARTMENT;
}

Target::~Target()
{
}

TargetType Target::GetType()
{
    return this->targetType;
}

uint Target::GetApartmentID()
{
    return this->apartment;
}

Point Target::GetPoint()
{
    return this->point;
}
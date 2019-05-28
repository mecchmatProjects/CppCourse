#pragma once

#include <iostream>

#include "common.hpp"
#include "Point.hpp"
#include "Way.hpp"
#include "Apartment.hpp"
#include "Flat.hpp"
#include "Target.hpp"
    

class Robot
{
private:
    uint stamina, max_stamina;
    Point position;
    double angle, sumOfMassX, sumOfMassY;
    Way way;
    Flat *flat;
    Target *target;
    double DistancePP(Point p1, Point p2);
    double DistancePP(double x1, double y1, double x2, double y2);
    double GetCos(Point p);
    Point CenterOfMass();
    int SignedTriangleArea(Point p1, Point p2, Point p3);
    std::pair<double, std::vector<Point> > Cross();
    Action NextAction();

public:
    Robot();
    Robot(Point start, uint max_stamina, Flat *flat, Target *target);
    void Start();
    ~Robot();
    uint GetCurrentApartmentId();
};

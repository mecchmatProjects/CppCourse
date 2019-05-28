#include <iostream>
#include <math.h>
#include <stdexcept>

#include "Robot.hpp"
#include "Point.hpp"

Robot::Robot()
{
}

Robot::~Robot()
{
}

void Robot::Start()
{
    std::cout << "Start!\n";
    this->NextAction();
    //this->NextAction();
}

Action Robot::NextAction()
{
    std::cout << "NextAction!\n";
    std::cout << this->angle << ' ' << this->position.GetX() << ' ' << this->position.GetY() << std::endl;
    this->sumOfMassX += this->position.GetX();
    this->sumOfMassY += this->position.GetY();
    this->stamina -= 1;
    std::pair<double, std::vector<Point>> rez = Cross();
    uint rN = rand() % rez.second.size();
    this->angle += GetCos(rez.second[rN]);
    this->position = rez.second[rN];
    std::cout << this->angle << ' ' << this->position.GetX() << ' ' << this->position.GetY() << std::endl;
}

double Robot::GetCos(Point p)
{
    double tangle = this->angle;
    Point rP = this->position;
    return ((p.GetX() - rP.GetX()) * cos(tangle) + (p.GetY() - rP.GetY()) * sin(tangle)) / DistancePP(p, rP);
}

int Robot::SignedTriangleArea(Point p1, Point p2, Point p3)
{
    return (p2.GetX() - p1.GetX()) * (p3.GetY() - p1.GetY()) - (p2.GetY() - p1.GetY()) * (p3.GetX() - p1.GetX());
}

uint Robot::GetCurrentApartmentId()
{
    for (int _r = 0; _r < this->flat->GetRoomsCount() + this->flat->GetHallsCount(); ++_r)
    {
        Apartment tempAp = this->flat->GetApartment(_r);
        bool can_be_current_apartment = true;

        for (int _d = 0; _d < tempAp.GetDoorsCount(); ++_d)
        {
            Door door = tempAp.GetDoor(_d);
            if (SignedTriangleArea(this->position, door.GetP1(), door.GetP2()) <= 0)
                can_be_current_apartment = false;
        }

        for (int _w = 0; _w < tempAp.GetWallsCount(); ++_w)
        {
            Wall wall = tempAp.GetWall(_w);
            if (SignedTriangleArea(this->position, wall.GetP1(), wall.GetP2()) <= 0)
                can_be_current_apartment = false;
        }

        if (can_be_current_apartment)
            return _r;
    }

    throw std::runtime_error("Cant fing current apartment");
}

std::pair<double, std::vector<Point>> Robot::Cross()
{
    double maxDist = -1;
    double _xmax = 0;
    double _ymax = 0;
    for (double t = -M_PI; t < 0; t += d_eps)
    {
        double K = tan(t);
        std::cout << "Angle:" << t << '\n';
        //Перевірка на завершення
        if (this->target->GetType() == POINT)
        {
            std::cout << "POINT!!!\n";
            double tx = this->target->GetPoint().GetX();
            double ty = this->target->GetPoint().GetY();
            if (abs((double)(K * (tx - this->position.GetX()) + this->position.GetY() - ty)) / (pow(1 + pow(K, 2), 1 / 2)) < d_eps)
            {
                return std::make_pair(-3, std::vector<Point>());
            }
        }

        //Перевірка на завершення
        if (this->target->GetType() == APARTMENT)
        {
            std::cout << "APARTMENT!!!\n";
            if (this->GetCurrentApartmentId() == this->target->GetApartmentID())
            {
                return std::make_pair(-4, std::vector<Point>());
            }
        }
        double posD, negD, posx, posy, negx, negy;
        for (int _r = 0; _r < this->flat->GetRoomsCount() + this->flat->GetHallsCount(); ++_r)
        {
            std::cout << "    Room #:" << _r << '\n'; 
            for (int _w = 0; _w < this->flat->GetApartment(_r).GetWallsCount(); ++_w)
            {
                std::cout << "        Wall #:" << _w << '\n'; 
                Wall twall = this->flat->GetApartment(_r).GetWall(_w);

                double tWallX1 = twall.GetP1().GetX();
                double tWallY1 = twall.GetP1().GetY();
                double tWallX2 = twall.GetP2().GetX();
                double tWallY2 = twall.GetP2().GetY();

                std::cout << "Wall: " << _w << " " << MIN(tWallX1, tWallX2) << ' ' << MAX(tWallX1, tWallX2) << std::endl;

                for (double _x = MIN(tWallX1, tWallX2); _x <= MAX(tWallX1, tWallX2); _x += d_eps)
                {
                    std::cout << "          X #:" << _x << '\n'; 
                    double _y = K * (_x - this->position.GetX()) + this->position.GetY();
                    if ((_x - tWallX1) / (tWallX2 - tWallX1) - (_y - tWallY1) / (tWallY2 - tWallY1) <= d_eps * d_eps)
                    {
                        if(_y >= this->position.GetY())
                        {
                            double _posD = DistancePP(this->position.GetX(), this->position.GetY(), _x, _y);
                            if(_posD < posD)
                            {
                                posD = _posD;
                                posx = _x;
                                posy = _y;
                            }
                        }
                        else
                        {
                            double _negD = DistancePP(this->position.GetX(), this->position.GetY(), _x, _y);
                            if(_negD < negD)
                            {
                                negD = _negD;
                                negx = _x;
                                negy = _y;
                            }
                        }
                    }
                }
            }
        }
        double _tDist = DistancePP(this->CenterOfMass().GetX(), this->CenterOfMass().GetY(), posx, posy);
        if (_tDist > maxDist)
        {
            maxDist = _tDist;
            _xmax = posx;
            _ymax = posy;
        }
        _tDist = DistancePP(this->CenterOfMass().GetX(), this->CenterOfMass().GetY(), negx, negy);
        if (_tDist > maxDist)
        {
            maxDist = _tDist;
            _xmax = negx;
            _ymax = negy;
        }
    }
    std::vector<Point> rezVec;
    rezVec.push_back(Point(_xmax, _ymax));
    return std::make_pair(1, rezVec);
}

Robot::Robot(Point start, uint max_stamina, Flat *flat, Target *target)
{
    this->position = start;
    this->angle = 0;
    this->max_stamina = max_stamina;
    this->stamina = stamina;
    this->flat = flat;
    this->target = target;
    this->sumOfMassX = 0;
    this->sumOfMassY = 0;
}

double Robot::DistancePP(Point p1, Point p2)
{
    return sqrt(pow(p1.GetX() - p2.GetX(), 2) + pow(p1.GetY() - p2.GetY(), 2));
}

double Robot::DistancePP(double x1, double y1, double x2, double y2)
{
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

Point Robot::CenterOfMass()
{
    return Point(sumOfMassX / (max_stamina - stamina), sumOfMassY / (max_stamina - stamina));
}
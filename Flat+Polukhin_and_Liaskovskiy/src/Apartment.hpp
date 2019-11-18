#pragma once

#include <vector>
#include <iostream>

#include "common.hpp"
#include "Wall.hpp"
#include "Door.hpp"

class Apartment
{
private:
    std::vector<Wall> walls;
    std::vector<Door> doors;

public:
    Apartment();
    ~Apartment();
    Wall GetWall(uint i);
    Door GetDoor(uint i);
    uint GetWallsCount();
    uint GetDoorsCount();
    std::vector<Wall> GetWalls();
    std::vector<Door> GetDoors();
    virtual bool isCorrect();
};
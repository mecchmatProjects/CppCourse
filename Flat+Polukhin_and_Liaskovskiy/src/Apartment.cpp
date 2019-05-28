#include "Apartment.hpp"

#include <iostream>

Apartment::Apartment()
{
    uint wallsCount, doorsCount;

    std::cout << "Number of walls:\n";
    std::cin >> wallsCount;

    for (size_t i = 0; i < wallsCount; i++)
    {
        Wall wall = Wall();
        walls.push_back(wall);
    }

    std::cout << "Number of doors:\n";
    std::cin >> doorsCount;

    for (size_t i = 0; i < doorsCount; i++)
    {
        Door door = Door();
        doors.push_back(door);
    }
}

Apartment::~Apartment()
{
}

Wall Apartment::GetWall(uint i)
{
    return this->walls[i];
}

Door Apartment::GetDoor(uint i)
{
    return this->doors[i];
}

uint Apartment::GetWallsCount(){
    return this->walls.size();
}

uint Apartment::GetDoorsCount(){
    return this->doors.size();
}

std::vector<Wall> Apartment::GetWalls()
{
    return this->walls;
}

std::vector<Door> Apartment::GetDoors()
{
    return this->doors;
}

bool Apartment::isCorrect()
{
    return true;
}
#include "Flat.hpp"
#include "Room.hpp"
#include "Hall.hpp"

Flat::Flat()
{
    std::cout << "Number of rooms:\n";
    std::cin >> roomsCount;
    for (size_t i = 0; i < roomsCount; i++)
    {
        Room room = Room();
        this->apartments.push_back(room);
    }

    std::cout << "Number of halls:\n";
    std::cin >> hallsCount;
    for (size_t i = 0; i < hallsCount; i++)
    {
        Hall hall = Hall();
        this->apartments.push_back(hall);
    }
}

Flat::~Flat()
{
}

uint Flat::GetRoomsCount(){
    return this->roomsCount;
}

uint Flat::GetHallsCount(){
    return this->hallsCount;
}

Apartment Flat::GetApartment(uint i)
{
    return this->apartments[i];
}

std::vector<Apartment> Flat::GetApartments()
{
    return this->apartments;
}

bool Flat::isComplete()
{
    return true;
}
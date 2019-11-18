#pragma once

#include <iostream>
#include <vector>

#include "common.hpp"
#include "Apartment.hpp"

class Flat
{
private:
    uint roomsCount, hallsCount;
    std::vector<Apartment> apartments;

public:
    Flat();
    ~Flat();
    uint GetRoomsCount();
    uint GetHallsCount();
    Apartment GetApartment(uint i);
    std::vector<Apartment> GetApartments();
    bool isComplete();
};
#pragma once

#include <vector>

#include "common.hpp"
#include "Apartment.hpp"
#include "Furniture.hpp"

class Room : public Apartment
{
private:
    std::vector<Furniture> furnitures;

public:
    Room();
    ~Room();
    Furniture GetFurniture(uint i);
    std::vector<Furniture> GetFurnitures();
    uint GetFurnitureCount();
};
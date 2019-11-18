#include "Room.hpp"
#include "Apartment.hpp"
#include "Furniture.hpp"

Room::Room() : Apartment::Apartment()
{
    uint furnitureCount;

    std::cout << "Number of furnitures:\n";
    std::cin >> furnitureCount;

    for (size_t i = 0; i < furnitureCount; i++)
    {
        Furniture furniture = Furniture();
        this->furnitures.push_back(furniture);
    }
}

Room::~Room()
{
}

Furniture Room::GetFurniture(uint i)
{
    return this->furnitures[i];
}

std::vector<Furniture> Room::GetFurnitures()
{
    return this->furnitures;
}

uint Room::GetFurnitureCount(){
    return this->furnitures.size();
}
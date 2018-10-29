#pragma once
#include <iostream>
#include <ctime>
#include "itemgenerator.h"
#include "room.h"

class RoomGenerator {

private:
	std::default_random_engine generator;
	ItemGenerator* item_generator;
	int Rand(size_t min, size_t max);
	char* generate_description(Room::SIZE size, Room::STATE state, Room::OBJECTS objects);
public:
	RoomGenerator(ItemGenerator* item_generator);
	~RoomGenerator();
	Room* create_room();
};
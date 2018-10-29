#pragma once
#include "random.h"
#include "itemgenerator.h"
#include "room.h"

class RoomGenerator {

private:
	Random* random;
	ItemGenerator* item_generator;
	char* generate_description(Room::SIZE size, Room::STATE state, Room::OBJECTS objects);
public:
	RoomGenerator(Random* random, ItemGenerator* item_generator);
	~RoomGenerator();
	Room* create_room();
};
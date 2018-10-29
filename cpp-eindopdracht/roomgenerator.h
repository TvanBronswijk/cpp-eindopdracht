#pragma once
#include "random.h"
#include "itemgenerator.h"
#include "room.h"

class RoomGenerator {

private:
	Random* random;
	ItemGenerator* item_generator;
	char* generate_description(Room::SIZE size, Room::STATE state, Room::OBJECTS objects);
	char* generate_hallway_description(Room::SIZE size, Room::HALLWAY_TYPE type, Room::HALLWAY_OBSTACLE obstacle);
public:
	RoomGenerator(Random* random, ItemGenerator* item_generator);
	~RoomGenerator();
	Room* create_room();
};
#include "roomgenerator.h"


RoomGenerator::RoomGenerator(Random* random, ItemGenerator* item_generator)
{
	this->random = random;
	this->item_generator = item_generator;
}


Room* RoomGenerator::create_room() 
{
	int size = random->get(2);
	int state = random->get(1);
	int objects = random->get(2);
	int amount_of_monsters = random->get(3);

	Room* room = new Room(generate_description(Room::SIZE(size), Room::STATE(state), Room::OBJECTS(objects)), 
		generate_hallway_description(Room::SIZE(random->get(2)), Room::HALLWAY_TYPE(random->get(2)), Room::HALLWAY_OBSTACLE(random->get(3))));
	room->type = Room::NORMAL;

	if (random->get(0, 100) < 100) {
		room->item = item_generator->create_item();
	}
	else
		room->item = nullptr;

	return room;
}

char* RoomGenerator::generate_description(Room::SIZE size, Room::STATE state, Room::OBJECTS objects)
{
	char* description = new char[512];

	strcpy_s(description, 512, "You stand in a ");
	switch (state) {
	case Room::CLEAN:
		strcat_s(description, 512, "clean, ");
		break;
	case Room::MESSY:
		strcat_s(description, 512, "messy, ");
		break;
	}
	switch (size) {
	case Room::SMALL:
		strcat_s(description, 512, "small ");
		break;
	case Room::MEDIUM:
		strcat_s(description, 512, "regular-sized ");
		break;
	case Room::LARGE:
		strcat_s(description, 512, "large ");
		break;
	}
	strcat_s(description, 512, "room. In the center of the room is ");
	switch (objects) {
	case Room::TABLE:
		strcat_s(description, 512, "a large table with four chairs.");
		break;
	case Room::BED:
		strcat_s(description, 512, "a small bed.");
		break;
	case Room::NOTHING:
		strcat_s(description, 512, "nothing.");
		break;
	}

	return description;
}

char* RoomGenerator::generate_hallway_description(Room::SIZE size, Room::HALLWAY_TYPE type, Room::HALLWAY_OBSTACLE obstacle)
{
	char* description = new char[512];

	strcpy_s(description, 512, "There is a ");
	switch (size) {
	case Room::SMALL:
		strcat_s(description, 512, "small, ");
		break;
	case Room::MEDIUM:
		strcat_s(description, 512, "regular-sized, ");
		break;
	case Room::LARGE:
		strcat_s(description, 512, "large, ");
		break;
	}
	switch (type) {
	case Room::WOOD:
		strcat_s(description, 512, "wooden ");
		break;
	case Room::STONE:
		strcat_s(description, 512, "stone ");
		break;
	case Room::BROKEN:
		strcat_s(description, 512, "broken ");
		break;
	}
	switch (obstacle) {
	case Room::BRIDGE:
		strcat_s(description, 512, "brige to go over.");
		break;
	case Room::STAIRCASE:
		strcat_s(description, 512, "staircase to climb.");
		break;
	case Room::DOOR:
		strcat_s(description, 512, "door to go through.");
		break;
	case Room::GATE:
		strcat_s(description, 512, "gate to pass.");
		break;
	}

	return description;
}



RoomGenerator::~RoomGenerator()
{
}



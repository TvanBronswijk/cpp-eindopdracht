#include "roomgenerator.h"


RoomGenerator::RoomGenerator(ItemGenerator* item_generator)
{
	generator.seed(time(0));
	this->item_generator = item_generator;
}

int RoomGenerator::Rand(size_t min, size_t max) 
{
	std::uniform_int_distribution<int> d(min, max);
    return d(generator);
}

Room* RoomGenerator::create_room() 
{
	int size = this->Rand(0, 2);
	int state = this->Rand(0, 1);
	int objects = this->Rand(0, 2);
	int amount_of_monsters = this->Rand(0, 3);

	Room* room = new Room(generate_description(Room::SIZE(size), Room::STATE(state), Room::OBJECTS(objects)));

	if (Rand(0, 100) < 100) {
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



RoomGenerator::~RoomGenerator()
{
}



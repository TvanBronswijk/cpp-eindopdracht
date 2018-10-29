#include "roomgenerator.h"


RoomGenerator::RoomGenerator(Random* random, MonsterGenerator* monster_generator , ItemGenerator* item_generator)
{
	this->random = random;
	this->monster_generator = monster_generator;
	this->item_generator = item_generator;
}


Room* RoomGenerator::create_room(size_t min, size_t max) 
{
	int size = random->get(2);
	int state = random->get(1);
	int objects = random->get(2);
	int amount_of_monsters = random->get(3);

	Room* room = new Room(generate_description(Room::SIZE(size), Room::STATE(state), Room::OBJECTS(objects)));
	
	for (int i = 0; i < amount_of_monsters; i++)
	{
		room->monsters->push(monster_generator->generate(min, max));
	}

	if (random->get(100) < 100) {
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



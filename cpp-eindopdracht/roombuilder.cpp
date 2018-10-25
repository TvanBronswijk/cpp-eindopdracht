#include "roombuilder.h"


RoomBuilder::RoomBuilder(MonsterGenerator* monster_generator)
{
	generator.seed(time(0));
	this->monster_generator = monster_generator;
}

int RoomBuilder::Rand(int min, int max) {
	std::uniform_int_distribution<int> d(min, max);
    return d(generator);
}

Room* RoomBuilder::CreateRoom(int min, int max) {
	int size = this->Rand(0, 2);
	int state = this->Rand(0, 1);
	int objects = this->Rand(0, 2);
	int amount_of_monsters = this->Rand(0, 3);

	Room* room = new Room(Room::SIZE(size), Room::STATE(state), Room::OBJECTS(objects));
	//need to add the monster in the Room
	for (size_t i = 0; i < amount_of_monsters; i++)
	{
		room->push(monster_generator->generate(min, max));
	}

	return room;
}

RoomBuilder::~RoomBuilder()
{
}



#include "roomBuilder.h"


RoomBuilder::RoomBuilder(std::default_random_engine generator , MonsterGenerator* monster_generator)
{
	this->generator = generator;
	this->monster_generator = monster_generator;
	_surroundings[0] = "with a table in the middle with four chairs around it.";
	_surroundings[1] = "with a bed in the corner off the room.";
	_surroundings[2] = "with nothing in the room.";
	_states[0] = "Clean";
	_states[1] = "messy";
	_bigness[0] = "small ";
	_bigness[1] = "Medium ";
	_bigness[2] = "Large ";
}

int RoomBuilder::Rand(int min, int max) {
	generator.seed(time(0));

	std::uniform_int_distribution<int> distribution1(min, max);
    return distribution1(generator);
}

Room RoomBuilder::CreateRoom(int min, int max) {
	int rand_bigness = this->Rand(0, 2);
	int rand_state = this->Rand(0, 1);
	int rand_surroundings = this->Rand(0, 2);
	int amount_of_monsters = this->Rand(0, 3);
	
	const char* bigness = _bigness[rand_bigness];
	const char* state = _states[rand_state];
	const char* surroundings = _surroundings[rand_surroundings];

	Room room(bigness, state, surroundings);
	//need to add the monster in the Room
	for (size_t i = 0; i < amount_of_monsters; i++)
	{
		room.push(monster_generator->generate(min, max));
	}

	return room;
}

RoomBuilder::~RoomBuilder()
{
}



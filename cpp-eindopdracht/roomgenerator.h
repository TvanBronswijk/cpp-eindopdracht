#pragma once
#include <iostream>
#include <random>
#include <ctime>
#include "monstergenerator.h"
#include "room.h"

class RoomGenerator {

private:
	std::default_random_engine generator;
	MonsterGenerator* monster_generator;
	int Rand(size_t min, size_t max);
	char* generate_description(Room::SIZE size, Room::STATE state, Room::OBJECTS objects);
public:
	RoomGenerator(MonsterGenerator* monster_generator);
	~RoomGenerator();
	Room* create_room(size_t min, size_t max);
};
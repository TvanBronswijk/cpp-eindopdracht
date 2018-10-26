#pragma once
#include "room.h"
#include "monstergenerator.h"
#include <iostream>
#include <random>
#include <ctime>

class RoomGenerator {

private:
	std::default_random_engine generator;
	MonsterGenerator* monster_generator;
	int Rand(size_t min, size_t max);
public:
	RoomGenerator(MonsterGenerator* monster_generator);
	~RoomGenerator();
	Room* CreateRoom(size_t min, size_t max);
};
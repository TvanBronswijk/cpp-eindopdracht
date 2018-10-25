#pragma once
#include "room.h"
#include "monstergenerator.h"
#include <iostream>
#include <random>
#include <ctime>

class RoomBuilder {

private:
	std::default_random_engine generator;
	MonsterGenerator* monster_generator;
	int Rand(int min, int max);
public:
	RoomBuilder(MonsterGenerator* monster_generator);
	~RoomBuilder();
	Room* CreateRoom(int min, int max);
};
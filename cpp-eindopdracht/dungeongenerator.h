#pragma once
#include "random.h"
#include "coord.h"
#include "roomgenerator.h"
#include "dungeon.h"

class DungeonGenerator 
{
private:
	Random* random;
	RoomGenerator* room_generator;
public:
	DungeonGenerator(Random* random, RoomGenerator* room_generator);
	Dungeon* generate(size_t w, size_t h);
	~DungeonGenerator();
};



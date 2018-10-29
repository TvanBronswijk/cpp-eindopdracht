#pragma once
#include "coord.h"
#include "roomgenerator.h"
#include "dungeon.h"

class DungeonGenerator 
{
private:
	RoomGenerator* room_generator;
public:
	DungeonGenerator(RoomGenerator* room_generator);
	Dungeon* generate(size_t w, size_t h);
	~DungeonGenerator();
};



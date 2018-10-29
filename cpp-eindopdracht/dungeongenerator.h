#pragma once
#include "random.h"
#include "coord.h"
#include "gameconfig.h"
#include "roomgenerator.h"
#include "dungeon.h"

class DungeonGenerator 
{
private:
	Random* random;
	RoomGenerator* room_generator;

	Coord random_coord(GameConfig* config, Coord exclude);
public:
	DungeonGenerator(Random* random, RoomGenerator* room_generator);
	Dungeon* generate(GameConfig* config, size_t level);
	~DungeonGenerator();
};



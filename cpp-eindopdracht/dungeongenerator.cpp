#include "dungeongenerator.h"

DungeonGenerator::DungeonGenerator(RoomGenerator* room_generator)
{
	this->room_generator = room_generator;
}

Dungeon* DungeonGenerator::Generate(size_t w, size_t h)
{
	Dungeon* result = new Dungeon(w, h);
	for (int x = 0; x < w; x++)
		for (int y = 0; y < h; y++)
			result->coord(x, y) = room_generator->create_room(1, 3);
	return result;
}

DungeonGenerator::~DungeonGenerator()
{
}

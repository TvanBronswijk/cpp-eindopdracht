#include "dungeongenerator.h"

DungeonGenerator::DungeonGenerator(Random* random, RoomGenerator* room_generator)
{
	this->random = random;
	this->room_generator = room_generator;
}

Dungeon* DungeonGenerator::generate(size_t w, size_t h)
{
	Dungeon* result = new Dungeon(w, h);
	for (size_t x = 0; x < w; x++) {
		for (size_t y = 0; y < h; y++) {
			Room* room = room_generator->create_room();
			result->coord(x, y) = room;
			room->coord = Coord(x, y);

			if (x > 0) {
				Room* other = result->coord(x - 1, y);
				other->right = room;
				room->left = other;
			}
			if (y > 0) {
				Room* other = result->coord(x, y - 1);
				other->down = room;
				room->up = other;
			}
		}
	}
	return result;
}

DungeonGenerator::~DungeonGenerator()
{
}

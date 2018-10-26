#include "dungeongenerator.h"

DungeonGenerator::DungeonGenerator(RoomGenerator* room_generator)
{
	this->room_generator = room_generator;
}

Dungeon* DungeonGenerator::Generate(size_t w, size_t h)
{
	Dungeon* result = new Dungeon(w, h);
	for (int x = 0; x < w; x++) {
		for (int y = 0; y < h; y++) {
			Room* room = room_generator->create_room(1, 3);
			result->coord(x, y) = room;
			room->x = x;
			room->y = y;

			if (x > 0) {
				Room* other = result->coord(x - 1, y);
				other->right = room;
				room->left = other;
			}
			if (y > 0) {
				Room* other = result->coord(x, y - 1);
				other->up = room;
				room->down = other;
			}
		}
	}
	return result;
}

DungeonGenerator::~DungeonGenerator()
{
}

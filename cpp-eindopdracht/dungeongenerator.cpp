#include "dungeongenerator.h"

DungeonGenerator::DungeonGenerator(Random* random, RoomGenerator* room_generator)
{
	this->random = random;
	this->room_generator = room_generator;
}

Dungeon* DungeonGenerator::generate(GameConfig* config, size_t level)
{
	Dungeon* result = new Dungeon(config->width(), config->height());
	for (size_t x = 0; x < result->width(); x++) {
		for (size_t y = 0; y < result->height(); y++) {
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

	if (level == 0) {
		Coord random_start = random_coord(config, Coord(0, 0));
		result->coord(random_start.x, random_start.y)->type = Room::START;
		Coord random_exit = random_coord(config, random_start);
		result->coord(random_exit.x, random_exit.y)->type = Room::DOWN;
	}
	else if (level == config->depth() - 1) {
		Coord random_start = random_coord(config, Coord(0, 0));
		result->coord(random_start.x, random_start.y)->type = Room::UP;
		Coord random_exit = random_coord(config, random_start);
		result->coord(random_exit.x, random_exit.y)->type = Room::BOSS;
	}
	else {
		Coord random_start = random_coord(config, Coord(0, 0));
		result->coord(random_start.x, random_start.y)->type = Room::UP;
		Coord random_exit = random_coord(config, random_start);
		result->coord(random_exit.x, random_exit.y)->type = Room::DOWN;
	}

	return result;
}

Coord DungeonGenerator::random_coord(GameConfig* config, Coord exclude)
{
	Coord result;
	do {
		result.x = random->get(config->width()-1);
		result.y = random->get(config->height()-1);
	} while (result.x == exclude.x && result.y == exclude.y);
	return result;
}


DungeonGenerator::~DungeonGenerator()
{
}

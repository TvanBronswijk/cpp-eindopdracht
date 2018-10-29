#include "gamecontext.h"

GameContext::GameContext()
{
	view_manager = new ViewManager();

	random = new Random();
	item_generator = new ItemGenerator(random);
	monster_generator = new MonsterGenerator(random);
	room_generator = new RoomGenerator(random, item_generator);
	dungeon_generator = new DungeonGenerator(random, room_generator);

	gamestate = nullptr;
}

GameContext::~GameContext()
{
	delete view_manager;
	delete random;
	delete item_generator;
	delete monster_generator;
	delete room_generator;
	delete dungeon_generator;
	delete gamestate;

}

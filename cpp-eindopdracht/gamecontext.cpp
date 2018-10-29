#include "gamecontext.h"

GameContext::GameContext()
{
	view_manager = new ViewManager();

	item_generator = new ItemGenerator();
	monster_generator = new MonsterGenerator();
	room_generator = new RoomGenerator(monster_generator, item_generator);
	dungeon_generator = new DungeonGenerator(room_generator);

	gamestate = new GameState();
}

GameContext::~GameContext()
{
	delete view_manager;
	delete gamestate;
	delete monster_generator;
	delete room_generator;
	delete dungeon_generator;
	delete item_generator;
}

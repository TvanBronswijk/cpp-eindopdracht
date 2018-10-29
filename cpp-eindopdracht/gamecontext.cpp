#include "gamecontext.h"

GameContext::GameContext()
{
	view_manager = new ViewManager();

	monster_generator = new MonsterGenerator();
	room_generator = new RoomGenerator(monster_generator);
	dungeon_generator = new DungeonGenerator(room_generator);

	gamestate = nullptr;
}

GameContext::~GameContext()
{
	delete view_manager;
	delete monster_generator;
	delete room_generator;
	delete dungeon_generator;
	delete gamestate;
}

#include "gamecontext.h"

GameContext::GameContext()
{
	view_manager = new ViewManager();
	monster_generator = new MonsterGenerator();
	room_builder = new RoomBuilder(monster_generator);
	dungeon_generator = new DungeonGenerator();
	gamestate = new GameState();
}

GameContext::~GameContext()
{
	delete view_manager;
	delete gamestate;
	delete monster_generator;
	delete room_builder;
	delete dungeon_generator;
}

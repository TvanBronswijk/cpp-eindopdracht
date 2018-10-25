#include "gamecontext.h"

GameContext::GameContext()
{
	view_manager = new ViewManager();
	gamestate = new GameState();
	monster_generator = new MonsterGenerator();
	room_builder = new RoomBuilder(monster_generator);
}

GameContext::~GameContext()
{
	delete view_manager;
	delete gamestate;
	delete monster_generator;
	delete room_builder;
}

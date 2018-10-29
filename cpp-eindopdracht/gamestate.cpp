#include "gamestate.h"

GameState::GameState()
{
	current_depth = 0;
}

Dungeon* GameState::get_dungeon()
{
	return dungeons.get(current_depth);
}

GameState::~GameState()
{
	delete config;
	delete player;
}
#include "gamestate.h"

GameState::GameState()
{

}

Dungeon * GameState::get_dungeon()
{
	return dungeon;
}

void GameState::set_dungeon(Dungeon * dungeon)
{
	this->dungeon = dungeon;
}

void GameState::set_player(Player* p)
{
	this->player = p;
}

Player* GameState::get_player() 
{
	return player;
}

void GameState::clear()
{
	delete dungeon;
}

GameState::~GameState()
{
	delete player;
}
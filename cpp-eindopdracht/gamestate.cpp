#include "gamestate.h"

GameState::GameState()
{

}

void GameState::save_player(Player* p)
{
	players.push(p);
}

Player* GameState::get_player(const char* name) 
{
	for (int i = 0; i < players.size(); i++) {
		if (players.all()[i]->name == name) 
			return players.all()[i];
	}
	return nullptr;
}

void GameState::clear()
{

}

GameState::~GameState()
{

}
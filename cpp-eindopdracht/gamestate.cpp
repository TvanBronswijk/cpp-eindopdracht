#include "gamestate.h"

GameState::GameState()
{

}

void GameState::push(Player* p)
{
	players.push(p);
}

Player* GameState::getPlayer(const char* name) 
{
	for (int i = 0; i < players.size(); i++) {
		if (players.all()[i]->name == name) 
			return players.all()[i];
	}
	return nullptr;
}

GameState::~GameState()
{

}
#include "gamestate.h"

GameState::GameState()
{
	this->_current = -1;
	player_stack = new Player*[MAX_PLAYERS];
}

void GameState::push(Player* p)
{
	if (this->_current < MAX_PLAYERS)
	{
		this->_current++;
		player_stack[this->_current] = p;

	}
	else
	{
		throw - 1;
	}
}

Player** GameState::getallPlayers() {
	return player_stack;
}

Player* GameState::getPlayer(const char* name) {
	for (int i = 0; i <= _current; i++) {
		if (player_stack[i]->name == name) return player_stack[i];
	}
		return nullptr;
}

int GameState::getamountofplayers() {
	return _current;
}


GameState::~GameState()
{
	for (int i = 0; i <= _current; i++)
		delete player_stack[i];
	delete[] player_stack;
}
#pragma once
#include "collection.h"
#include "player.h"

class GameState
{
private:
	Collection<Player*, 32> players;
public:
	GameState();
	~GameState();
	void push(Player* p);
	Player* getPlayer(const char* name);
};
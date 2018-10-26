#pragma once
#include "collection.h"
#include "player.h"

class GameState
{
private:
	Collection<Player*, 32> players;
public:
	GameState();
	void save_player(Player* p);
	Player* get_player(const char* name);
	void clear();
	~GameState();
};
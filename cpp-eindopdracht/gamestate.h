#pragma once
#include "collection.h"
#include "dungeon.h"
#include "player.h"

class GameState
{
private:
	Dungeon* dungeon;
	Collection<Player, 32> players;
public:
	GameState();
	Dungeon* get_dungeon();
	void set_dungeon(Dungeon* dungeon);
	void save_player(Player* p);
	Player* get_player(const char* name);
	void clear();
	~GameState();
};
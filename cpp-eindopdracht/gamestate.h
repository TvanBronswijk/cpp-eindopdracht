#pragma once
#include "ptrarray.h"
#include "dungeon.h"
#include "player.h"

class GameState
{
private:
	Dungeon* dungeon;
	Player* player;
public:
	GameState();
	Dungeon* get_dungeon();
	void set_dungeon(Dungeon* dungeon);
	void set_player(Player* p);
	Player* get_player();
	void clear();
	~GameState();
};
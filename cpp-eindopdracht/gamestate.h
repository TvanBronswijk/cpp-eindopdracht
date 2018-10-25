#pragma once
#include "player.h"

class GameState
{
private:
	const static int MAX_PLAYERS = 32;
	int _current;
	Player** player_stack;
public:
	GameState();
	~GameState();
	void push(Player* p);
	int getamountofplayers();
	Player** getallPlayers();
	Player* getPlayer(const char* name);
};
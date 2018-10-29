#pragma once
#include "ptrarray.h"
#include "dungeon.h"
#include "player.h"

struct GameState
{
public:
	Dungeon* dungeon;
	Player* player;

	GameState();
	~GameState();
};
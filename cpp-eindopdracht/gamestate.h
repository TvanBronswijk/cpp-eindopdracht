#pragma once
#include "gameconfig.h"
#include "dungeon.h"
#include "player.h"

struct GameState
{
	GameConfig* config;
	Dungeon* dungeon;
	Player* player;

	GameState();
	~GameState();
};
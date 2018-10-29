#pragma once
#include "gameconfig.h"
#include "ptrarray.h"
#include "dungeon.h"
#include "player.h"

struct GameState
{
	PtrArray<Dungeon, 16> dungeons;
	GameConfig* config;
	Player* player;

	size_t current_depth;
	Dungeon* get_dungeon();

	GameState();
	~GameState();
};
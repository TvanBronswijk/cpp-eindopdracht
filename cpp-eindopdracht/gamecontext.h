#pragma once
#include "viewmanager.h"
#include "dungeongenerator.h"
#include "monstergenerator.h"
#include "roombuilder.h"
#include "gamestate.h"

class GameContext {
private:

public:
	ViewManager* view_manager;
	MonsterGenerator* monster_generator;
	RoomBuilder* room_builder;
	DungeonGenerator* dungeon_generator;
	GameState* gamestate;

	GameContext();
	~GameContext();
};
#pragma once
#include "viewmanager.h"
#include "gamestate.h"
#include "monstergenerator.h"
#include "roombuilder.h"

class GameContext {
private:

public:
	ViewManager* view_manager;
	GameState* gamestate;
	MonsterGenerator* monster_generator;
	RoomBuilder* room_builder;

	GameContext();
	~GameContext();
};
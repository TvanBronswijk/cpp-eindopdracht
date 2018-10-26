#pragma once
#include "viewmanager.h"
#include "dungeongenerator.h"
#include "monstergenerator.h"
#include "roomgenerator.h"
#include "gamestate.h"

class GameContext {
private:

public:
	ViewManager* view_manager;
	MonsterGenerator* monster_generator;
	RoomGenerator* room_generator;
	DungeonGenerator* dungeon_generator;

	GameState* gamestate;

	GameContext();
	~GameContext();
};
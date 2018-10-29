#pragma once
#include "random.h"
#include "viewmanager.h"
#include "dungeongenerator.h"
#include "monstergenerator.h"
#include "roomgenerator.h"
#include "gamestate.h"

class GameContext {
private:

public:
	Random* random;

	ViewManager* view_manager;
	MonsterGenerator* monster_generator;
	RoomGenerator* room_generator;
	DungeonGenerator* dungeon_generator;
	ItemGenerator* item_generator;

	GameState* gamestate;

	GameContext();
	~GameContext();
};
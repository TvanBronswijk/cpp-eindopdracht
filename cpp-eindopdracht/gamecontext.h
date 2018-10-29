#pragma once
#include "random.h"
#include "savemanager.h"
#include "viewmanager.h"
#include "dungeongenerator.h"
#include "monstergenerator.h"
#include "roomgenerator.h"
#include "itemgenerator.h"
#include "gamestate.h"

class GameContext {
private:

public:
	Random* random;

	SaveManager* save_manager;
	ViewManager* view_manager;

	MonsterGenerator* monster_generator;
	RoomGenerator* room_generator;
	DungeonGenerator* dungeon_generator;
	ItemGenerator* item_generator;

	GameState* gamestate;

	GameContext();
	~GameContext();
};
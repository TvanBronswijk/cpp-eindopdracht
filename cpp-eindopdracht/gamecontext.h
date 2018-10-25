#pragma once
#include "viewmanager.h"
#include "gamestate.h"

class GameContext {
private:

public:
	ViewManager* view_manager;
	GameState* gamestate;

	GameContext();
	~GameContext();
};
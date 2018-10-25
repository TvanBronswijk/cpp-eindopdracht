#include "gamecontext.h"

GameContext::GameContext()
{
	view_manager = new ViewManager();
	gamestate = new GameState();
}

GameContext::~GameContext()
{
	delete view_manager;
	delete gamestate;
}

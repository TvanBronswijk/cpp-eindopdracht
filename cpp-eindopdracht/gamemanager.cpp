#include "gamemanager.h"

void GameManager::init() 
{
	MainView* mv = new MainView();
	view_manager.display(mv);
}
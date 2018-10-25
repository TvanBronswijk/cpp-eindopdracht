#include "gamemanager.h"

GameManager::GameManager()
{
	context = new GameContext();
}

void GameManager::init()
{
	context->view_manager->display(new MainView(context));
	context->view_manager->handle_input();
}

GameManager::~GameManager()
{
	delete context;
}

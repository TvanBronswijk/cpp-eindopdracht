#include "gamemanager.h"

GameManager::GameManager()
{
	context = new GameContext();
}

void GameManager::init()
{
	context->monster_generator->init();
	context->view_manager->push(new MainView(context));
}

void GameManager::run()
{
	while (1)
	{
		context->view_manager->display();
		while (!context->view_manager->handle_input()) {
			std::cout << "Invalid input." << std::endl;
		}
		if (context->view_manager->is_empty()) {
			break;
		}
	}
}

GameManager::~GameManager()
{
	delete context;
}

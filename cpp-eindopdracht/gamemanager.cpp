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
		if (context->view_manager->is_empty()) {
			break;
		}

	    context->view_manager->display();
		while (!context->view_manager->handle_input()) {
			std::cout << "Invalid input." << std::endl;
		}
		std::cout << std::endl << std::endl;
	}
}

GameManager::~GameManager()
{
	delete context;
}

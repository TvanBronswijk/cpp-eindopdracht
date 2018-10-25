#include "gamemanager.h"

GameManager::GameManager(std::default_random_engine generator)
{
	context = new GameContext();

	monster_generator = new MonsterGenerator(generator);
	monster_generator->init();
}

void GameManager::init()
{
	context->view_manager->display(new MainView(context));
	context->view_manager->handle_input();
}

GameManager::~GameManager()
{
	delete context;
	delete monster_generator;
}

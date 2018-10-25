#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>  
#include <iostream>
#include <random>
#include <ctime>
#include "gamemanager.h"
#include "monstergenerator.h"

int main()
{
	std::default_random_engine generator;
	generator.seed(time(0));

	GameManager* manager = new GameManager(generator);
	manager->init();
	delete manager;

	//memory leak detection
	_CrtDumpMemoryLeaks();

	//exit
	return 0;
}
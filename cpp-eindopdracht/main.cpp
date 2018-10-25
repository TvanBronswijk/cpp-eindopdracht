#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>  
#include <iostream>
#include "gamemanager.h"

int main()
{
	//game logic
	GameManager* manager = new GameManager();
	manager->init();
	manager->run();
	delete manager;

	//memory leak detection
	_CrtDumpMemoryLeaks();

	//exit
	return 0;
}
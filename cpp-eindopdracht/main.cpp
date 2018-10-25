#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>  
#include <iostream>
#include "gamemanager.h"

int main()
{
	GameManager* manager = new GameManager();
	manager->init();

	//memory leak detection
	_CrtDumpMemoryLeaks();

	delete manager;
	//exit
	return 0;
}
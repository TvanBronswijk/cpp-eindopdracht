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

	auto mg = new MonsterGenerator();
	mg->init();
	auto rb = new RoomBuilder(mg);

	auto r = rb->CreateRoom(1, 3);

	std::cout << r->to_string() << std::endl;

	char a;
	std::cin >> a;

	//memory leak detection
	_CrtDumpMemoryLeaks();

	//exit
	return 0;
}
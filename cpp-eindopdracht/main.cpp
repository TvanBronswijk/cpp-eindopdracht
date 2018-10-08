#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>  

#include <iostream>
#include "gamemanager.h"

int main()
{
	GameManager manager;
	manager.init();

	//memory leak detection
	_CrtDumpMemoryLeaks();

	//exit
	return 0;
}
#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>  

#include <iostream>
#include "dungeon.h"
#include "room.h"

int main()
{
	Dungeon<12, 16> *dungeon = new Dungeon<12,16>();
	dungeon->Coord(1, 1) = new Room();

	Room *room = dungeon->Coord(1, 1);
	std::cout << room->Description() << std::endl;
	delete dungeon;
	system("pause");
	_CrtDumpMemoryLeaks();
	return 0;
}
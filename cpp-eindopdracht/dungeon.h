#pragma once
#include "room.h"

template <size_t w, size_t h>
struct Dungeon 
{
private:
	Room* rooms[w*h];
public:
	Room*& Coord(int x, int y)
	{
		return rooms[x * h + y];
	}
};

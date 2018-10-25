#pragma once
#include "room.h"

struct Dungeon 
{
private:
	size_t w;
	size_t h;
	Room** rooms;
public:
	Dungeon(size_t w, size_t h)
	{
		this->w = w;
		this->h = h;
		this->rooms = new Room*[w*h];
	}
	Room* Coord(size_t x, size_t y)
	{
		return rooms[x * h + y];
	}
};

#pragma once
#include "room.h"

struct Dungeon 
{
private:
	size_t _w;
	size_t _h;
	Room** _rooms;
public:
	Dungeon(size_t w, size_t h);
	Room*& Coord(size_t x, size_t y);
	~Dungeon();
};

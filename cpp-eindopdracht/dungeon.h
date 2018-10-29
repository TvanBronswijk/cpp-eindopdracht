#pragma once
#include "coord.h"
#include "room.h"

struct Dungeon 
{
private:
	size_t _w;
	size_t _h;
	Room** _rooms;
public:
	Dungeon(size_t w, size_t h);
	Room*& coord(Coord coord);
	Room*& coord(size_t x, size_t y);
	size_t width();
	size_t height();
	Room*& find(Room::TYPE type);
	~Dungeon();
};

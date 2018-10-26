#include "dungeon.h"

Dungeon::Dungeon(size_t w, size_t h)
{
	this->_w = w;
	this->_h = h;
	this->_rooms = new Room*[w*h];
}

Room*& Dungeon::coord(size_t x, size_t y)
{
	return _rooms[x * _h + y];
}

Dungeon::~Dungeon()
{
	for (int i = 0; i < _w*_h; i++)
		delete _rooms[i];
	delete[] _rooms;
}

#include "dungeon.h"

Dungeon::Dungeon(size_t w, size_t h)
{
	this->_w = w;
	this->_h = h;
	this->_rooms = new Room*[w*h];
}

Room*& Dungeon::coord(Coord coord)
{
	return this->coord(coord.x, coord.y);
}

Room*& Dungeon::coord(size_t x, size_t y)
{
	return _rooms[x * _h + y];
}

size_t Dungeon::width()
{
	return _w;
}

size_t Dungeon::height()
{
	return _h;
}

Room*& Dungeon::find(Room::TYPE type)
{
	for (size_t i = 0; i < _w*_h; i++)
		if (_rooms[i]->type == type)
			return _rooms[i];
}

Dungeon::~Dungeon()
{
	for (size_t i = 0; i < _w*_h; i++)
		delete _rooms[i];
	delete[] _rooms;
}

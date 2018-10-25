#include "room.h"

Room::Room(const char* bigness, const char* state, const char* enviroment) {
	this->_current = -1;
	this->_bigness = bigness;
	this->_enviroment = enviroment;
	this->_state = state;
	_monsters = new Monster*[MAX_MONSTERS];
}

void Room::push(Monster* v)
{
	if (this->_current < MAX_MONSTERS)
	{
		this->_current++;
		_monsters[this->_current] = v;

	}
	else
	{
		throw - 1;
	}
}

Room::~Room()
{
	for (int i = 0; i <= _current; i++)
		delete _monsters[i];
	delete[] _monsters;
}

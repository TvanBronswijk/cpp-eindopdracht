#include "player.h"

Player::Player(const char* name) {
	_items = new Item*[MAX_ITEMS];
	this->_current = -1;
	this->_size = 0;

	this->name = name;
	this->level = 1;
	this->health = 100;
	this->attack = 10;
	this->defence = 10;
	this->exp = 0;
}

void Player::push(Item* i)
{
	if (this->_current < MAX_ITEMS)
	{
		this->_current++;
		_items[this->_current] = i;
		if (_current > _size)
			_size = _current;
	}
	else
	{
		throw - 1;
	}
}

const char* Player::to_string()
{
	return this->name;
}


Player::~Player() {
	for (int i = 0; i <= _size; i++)
		delete _items[i];
	delete[] _items;
}
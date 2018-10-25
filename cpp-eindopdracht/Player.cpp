#include "player.h"

Player::Player(const char* name) {
	this->_current = -1;
	this->_name = name;
	this->_level = 1;
	this->_health = 100;
	this->_attack = 10;
	this->_defence = 10;
	this->_exp = 0;
	_items = new Item*[MAX_ITEMS];
}

void Player::push(Item* i)
{
	if (this->_current < MAX_ITEMS)
	{
		this->_current++;
		_items[this->_current] = i;

	}
	else
	{
		throw - 1;
	}
}


Player::~Player() {
	for (int i = 0; i <= _current; i++)
		delete _items[i];
	delete[] _items;
}
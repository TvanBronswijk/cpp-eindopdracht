#pragma once
#include "item.h"

struct Player
{
private:
	int _current;
	const static int MAX_ITEMS = 32;
	Item** _items;
public:
	const char* _name;
	int _level;
	int _health;
	int _exp;
	int _attack;
	int _defence;
	Player(const char* name);
	~Player();
	void push(Item* i);

	const char* to_string() {
		return this->_name;
	}
};
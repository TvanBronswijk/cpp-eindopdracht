#pragma once
#include "item.h"

struct Player
{
private:
	const static int MAX_ITEMS = 32;
	int _current;
	size_t _size;
	Item** _items;
public:
	const char* name;
	int level;
	int health;
	int exp;
	int attack;
	int defence;
	Player(const char* name);
	~Player();
	void push(Item* i);

	const char* to_string();
};
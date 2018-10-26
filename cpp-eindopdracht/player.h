#pragma once
#include "ptrarray.h"
#include "item.h"

struct Player
{
private:

public:
	const char* name;
	int level;
	int health;
	int exp;
	int attack;
	int defence;
	PtrArray<Item, 32> items;
	Player(const char* name);
	~Player();

	const char* to_string();
};
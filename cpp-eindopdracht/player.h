#pragma once
#include "ptrarray.h"
#include "item.h"

struct Player
{
private:

public:
	const char* name;
	int exp;
	int level;
	int max_health;
	int current_health;
	int attack;
	int defense;
	PtrArray<Item, 32> items;
	Player(const char* name);
	~Player();

	const char* to_string();
};
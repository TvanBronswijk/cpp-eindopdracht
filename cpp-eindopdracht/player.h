#pragma once
#include "set.h"
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
	Item* equiped;
	Set<Item, 10> potions;
	Set<Item, 10> items;
	Player(const char* name);
	~Player();

	const char* to_string();
};
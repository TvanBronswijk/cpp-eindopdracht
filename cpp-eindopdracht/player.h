#pragma once
#include "set.h"
#include "item.h"

struct Player
{
private:

public:
	const char* name;
	int exp;
	int exp_for_next_level;
	int level;
	int max_health;
	int current_health;
	int attack;
	int defense;
	Item* equiped;
	Set<Item, 64> potions;
	Set<Item, 64> items;
	Player(const char* name);
	~Player();

	const char* to_string();
};
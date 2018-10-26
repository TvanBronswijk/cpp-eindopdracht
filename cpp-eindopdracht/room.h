#pragma once
#include <iostream>
#include "monster.h"
#include "collection.h"

struct Room {
	enum SIZE {SMALL, MEDIUM, LARGE};
	enum STATE {CLEAN, MESSY};
	enum OBJECTS {TABLE, BED, NOTHING};

private:
	char* description;
public:
	Collection<Monster, 32> monsters;
	Room(SIZE size, STATE state, OBJECTS objects);
	~Room();
	
	const char* to_string();
};
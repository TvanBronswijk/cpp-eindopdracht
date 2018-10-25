#pragma once
#include <iostream>
#include "monster.h"
#include "collection.h"

struct Room {
	enum SIZE {SMALL, MEDIUM, LARGE};
	enum STATE {CLEAN, MESSY};
	enum OBJECTS {TABLE, BED, NOTHING};

private:
	SIZE _room_size;
	STATE _state;
	OBJECTS _objects;
public:
	Collection<Monster*, 32> monsters;
	Room(SIZE size, STATE state, OBJECTS objects);
	~Room();
	
	char* to_string();
};
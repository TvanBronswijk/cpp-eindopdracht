#pragma once
#include <iostream>
#include "monster.h"

struct Room {
	enum SIZE {SMALL, MEDIUM, LARGE};
	enum STATE {CLEAN, MESSY};
	enum OBJECTS {TABLE, BED, NOTHING};

private:
	const static int MAX_MONSTERS = 32;
	int _current;
	size_t _size;
	Monster** _monsters;

	SIZE _room_size;
	STATE _state;
	OBJECTS _objects;
public:
	Room(SIZE size, STATE state, OBJECTS objects);
	~Room();
	void push(Monster* v);
	
	char* to_string();
};
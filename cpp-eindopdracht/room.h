#pragma once
#include <iostream>
#include "monster.h"
#include "ptrarray.h"

struct Room {
	enum SIZE {SMALL, MEDIUM, LARGE};
	enum STATE {CLEAN, MESSY};
	enum OBJECTS {TABLE, BED, NOTHING};

private:
	char* description;
public:
	PtrArray<Monster, 32>* monsters;
	Room* up;
	Room* down;
	Room* left;
	Room* right;

	size_t x;
	size_t y;

	bool visited;

	Room(char* description);
	~Room();
	
	const char* to_string();
};
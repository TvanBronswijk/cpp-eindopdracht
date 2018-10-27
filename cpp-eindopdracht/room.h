#pragma once
#include <iostream>
#include "coord.h"
#include "ptrarray.h"
#include "monster.h"

struct Room {
	enum SIZE {SMALL, MEDIUM, LARGE};
	enum STATE {CLEAN, MESSY};
	enum OBJECTS {TABLE, BED, NOTHING};

private:
	char* description;
public:
	Coord coord;
	PtrArray<Monster, 32>* monsters;
	Room* up;
	Room* down;
	Room* left;
	Room* right;

	bool visited;

	Room(char* description);
	~Room();
	
	const char* to_string();
};
#pragma once
#include <iostream>
#include "coord.h"
#include "ptrarray.h"
#include "monster.h"
#include "item.h"

struct Room {
	enum SIZE {SMALL, MEDIUM, LARGE};
	enum STATE {CLEAN, MESSY};
	enum OBJECTS {TABLE, BED, NOTHING};

	enum TYPE{NORMAL, UP, DOWN, START, BOSS};

private:
	char* description;
public:
	TYPE type;
	Coord coord;
	bool visited;

	Room* up;
	Room* down;
	Room* left;
	Room* right;
	
	Item* item;

	Room(char* description);
	~Room();
	
	const char* to_string();
};
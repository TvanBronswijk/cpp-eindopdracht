#pragma once
#include "coord.h"
#include "item.h"

struct Room {
	enum SIZE {SMALL, MEDIUM, LARGE};
	enum STATE {CLEAN, MESSY};
	enum OBJECTS {TABLE, BED, NOTHING};
	enum TYPE {WOOD, STONE, BROKEN};
	enum OBSTACLE {BRIDGE, DOOR, GATE, STAIRCASE};

	enum TYPE{NORMAL, UP, DOWN, START, BOSS};

private:
	char* description;
	char* hallway_description;
public:
	TYPE type;
	Coord coord;
	bool visited;

	Room* up;
	Room* down;
	Room* left;
	Room* right;
	
	Item* item;

	Room(char* description, char* hallway_description);
	~Room();
	
	const char* to_string();
	const char* hallway_to_string();
};
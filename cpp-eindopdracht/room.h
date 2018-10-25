#pragma once
#include "monster.h"

struct Room {
private:
	int _current;
	const static int MAX_MONSTERS = 32;
	Monster** _monsters;

public:
	const char* _bigness;
	const char* _state;
	const char* _enviroment;
	Room(const char* bigness, const char* state, const char* enviroment);
	~Room();
	void push(Monster* v);
};
#pragma once
#include "monster.h"

struct Room {
private:
	int _current;
	const static int MAX_MONSTERS = 32;
	Monster** _monsters;

public:
	const char* _size;
	const char* _state;
	const char* _environment;
	Room(const char* size, const char* state, const char* environment);
	~Room();
	void push(Monster* v);
};
#pragma once
#include "room.h"
#include <iostream>
#include <random>
#include <ctime>

class RoomBuilder {

private:
	int Rand(int min, int max);
	const char*  _states[3];
	const char*  _bigness[3];
	const char*  _surroundings[3];
public:
	RoomBuilder();
	~RoomBuilder();
	Room CreateRoom();
};
#include "room.h"

Room::Room(char* description) {	
	this->monsters = new PtrArray<Monster, 32>();
	this->description = description;
}

const char* Room::to_string()
{
	return this->description;
}

Room::~Room()
{
	delete[] description;
	delete monsters;
}

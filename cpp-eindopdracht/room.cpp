#include "room.h"

Room::Room(char* description) {	
	this->description = description;
}

const char* Room::to_string()
{
	return this->description;
}

Room::~Room()
{
	delete[] description;
}

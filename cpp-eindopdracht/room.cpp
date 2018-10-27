#include "room.h"

Room::Room(char* description) {	
	this->up = nullptr;
	this->down = nullptr;
	this->left = nullptr;
	this->right = nullptr;
	this->monsters = new PtrArray<Monster, 32>();
	this->description = description;
	this->visited = false;
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

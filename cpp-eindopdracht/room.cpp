#include "room.h"

Room::Room(char* description, char* hallway_description) {	
	this->up = nullptr;
	this->down = nullptr;
	this->left = nullptr;
	this->right = nullptr;
	this->description = description;
	this->hallway_description = hallway_description;
	this->visited = false;
	this->item = nullptr;
}

const char* Room::to_string()
{
	return this->description;
}

const char* Room::hallway_to_string()
{
	return this->hallway_description;
}

Room::~Room()
{
	delete[] description;
	delete item;
}

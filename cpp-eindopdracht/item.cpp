#include "item.h"

Item::Item(char * name)
{
	this->name = name;
}

char * Item::to_string()
{
	return name;
}

Item::~Item()
{
	delete[] name;
}

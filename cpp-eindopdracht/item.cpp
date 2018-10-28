#include "item.h"

Item::Item(const char* name)
{
	this->name = name;
}

const char * Item::to_string()
{
	return name;
}

Item::~Item()
{
	delete[] name;
}

#include "item.h"

Item::Item(const char* name, const char* details)
{
	this->name = name;
	this->detail = details;
}

const char * Item::details()
{
	return detail;
}

const char * Item::to_string()
{
	return name;
}

Item::~Item()
{
	delete[] name;
	delete[] detail;
}

#include "item.h"

Item::Item(const char* name, const char* details)
{
	this->name = new char[64];
	strcpy_s(this->name, 64, name);
	this->details = new char[512];
	strcpy_s(this->details, 64, details);
	delete[] details;
}

const char* Item::get_details()
{
	return details;
}

const char* Item::to_string()
{
	return name;
}

Item::~Item()
{
	delete[] name;
	delete[] details;
}

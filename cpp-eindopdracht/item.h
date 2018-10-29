#pragma once
#include <iostream>

class Item
{
protected:
	char* name;
	char* details;
	virtual const char* generate_details(const char* name, int value) = 0;
public:
	Item(const char* name, const char* details);
	virtual const char* get_details();
	virtual const char get_type() = 0;
	virtual int get_value() = 0;
	virtual const char* to_string();
	virtual ~Item();
};
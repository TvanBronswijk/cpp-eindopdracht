#pragma once
#include <iostream>

class Item
{
private:
	const char* name;
	const char* detail;
public:
	Item(const char* name, const char* details);
	virtual const char* details();
	virtual const char get_type() = 0;
	virtual int get_int() = 0;
	virtual const char* to_string();
	virtual ~Item();
};
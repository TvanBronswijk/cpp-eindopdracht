#pragma once
#include <iostream>

class Item
{
private:
	const char* name;
public:
	Item(const char* name);
	virtual void details() = 0;
	virtual const char get_type() = 0;
	virtual int get_int() = 0;
	virtual const char* to_string();
	virtual ~Item();
};
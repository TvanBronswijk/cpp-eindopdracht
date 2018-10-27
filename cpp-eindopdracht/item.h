#pragma once
class Item
{
private:
	char* name;
public:
	Item(char* name);
	virtual void excute() = 0;
	virtual void details() = 0;
	virtual char* to_string();
	virtual ~Item();
};
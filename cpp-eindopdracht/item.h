#pragma once
class Item
{
private:
public:
	virtual void excute() = 0;
	virtual void details() = 0;
	virtual ~Item() {}
};
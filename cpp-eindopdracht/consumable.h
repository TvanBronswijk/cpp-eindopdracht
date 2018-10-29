#pragma once
#include "item.h"

class Consumable : public Item
{
private:
	int _heath;
	const char* details(const char* name, int health);
public:
	Consumable(const char* name, int health);
	const char get_type() override;
	int get_int() override;
	~Consumable();
};
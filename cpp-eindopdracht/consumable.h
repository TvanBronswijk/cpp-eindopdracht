#pragma once
#include "item.h"

class Consumable : public Item
{
private:
	int _heath;
public:
	Consumable(const char* name, int health);
	void details() override;
	const char get_type() override;
	int get_int() override;
	~Consumable();
};
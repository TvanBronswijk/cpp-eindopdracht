#pragma once
#include "item.h"

class Consumable : public Item
{
private:
	int _health;
	const char* generate_details(const char* name, int value) override;
public:
	Consumable(const char* name, int health);
	const char get_type() override;
	const int get_value() override;
	~Consumable();
};
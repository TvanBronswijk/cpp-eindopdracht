#pragma once
#include "item.h"

class Weapon : public Item
{
private:
	int _damage;
public:
	Weapon(const char* name, int damage);
	void details() override;
	const char get_type() override;
	int get_int() override;
	~Weapon();
};
#pragma once
#include "item.h"

class Weapon : public Item
{
private:
	int _damage;
	const char* details(const char* name, int damage);
public:
	Weapon(const char* name, int damage);
	const char get_type() override;
	int get_int() override;
	~Weapon();
};
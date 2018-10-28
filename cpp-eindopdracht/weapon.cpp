#include "weapon.h"

Weapon::Weapon(const char* name, int damage) : Item(name) {
	this->_damage = damage;
}

void Weapon::details() {
	std::cout << this->to_string() << " has a damage of " << this->_damage;
}

int Weapon::get_int() {
	return this->_damage;
}

const char Weapon::get_type() {
	return 'w';
}

Weapon::~Weapon() {
}
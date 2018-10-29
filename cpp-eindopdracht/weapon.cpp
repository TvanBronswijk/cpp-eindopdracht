#include "weapon.h"

Weapon::Weapon(const char* name, int damage) : Item(name, details(name, damage)) {
	this->_damage = damage;
}

const char* Weapon::details(const char* name, int damage) {
	char* details = new char[512];
	char digit[3];
	_itoa_s(damage, digit, 3, 10);
	strcpy_s(details,512, name);
	strcat_s(details,512, " that has a attack of ");
	strcat_s(details, 512, digit);
	return details;
}

int Weapon::get_int() {
	return this->_damage;
}

const char Weapon::get_type() {
	return 'w';
}

Weapon::~Weapon() {
}
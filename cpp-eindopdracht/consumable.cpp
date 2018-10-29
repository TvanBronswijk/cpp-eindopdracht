#include "consumable.h"

Consumable::Consumable(const char* name, int health) : Item(name, details(name, health)) {
	this->_heath = health;
}

const char* Consumable::details(const char* name, int health) {
	char* details = new char[512];
	char digit[3];

	_itoa_s(health, digit, 3, 10);
	strcpy_s(details,512, name);
	strcat_s(details,512, " that restores ");
	strcat_s(details, 512, digit);
	strcat_s(details,512, " health");
	return details;
}

int Consumable::get_int() {
	return this->_heath;
}

const char Consumable::get_type() {
	return 'c';
}

Consumable::~Consumable() {
}
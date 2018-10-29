#include "consumable.h"


Consumable::Consumable(const char* name, int health) : Item(name, generate_details(name, health)) {
	this->_health = health;
}

int Consumable::get_int() {
	return this->_health;
}

const char Consumable::get_type() {
	return 'c';
}

Consumable::~Consumable() {
}

const char * Consumable::generate_details(const char * name, int value)
{
	char* details = new char[512];
	char digit[3];

	_itoa_s(value, digit, 3, 10);
	strcpy_s(details, 512, name);
	strcat_s(details, 512, " that restores ");
	strcat_s(details, 512, digit);
	strcat_s(details, 512, " health");

	return details;
}
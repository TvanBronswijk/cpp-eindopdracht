#include "consumable.h"

Consumable::Consumable(const char* name, int health) : Item(name) {
	this->_heath = health;
}

void Consumable::details() {
	std::cout << this->to_string() << " has a heath boost of " << this->_heath;
}

int Consumable::get_int() {
	return this->_heath;
}

const char Consumable::get_type() {
	return 'c';
}

Consumable::~Consumable() {
}
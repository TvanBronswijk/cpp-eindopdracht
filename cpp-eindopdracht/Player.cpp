#include "player.h"

Player::Player(const char* name) {
	this->name = name;
	this->level = 1;
	this->health = 100;
	this->attack = 10;
	this->defence = 10;
	this->exp = 0;
}

const char* Player::to_string()
{
	return this->name;
}


Player::~Player() {
	delete[] name;
}
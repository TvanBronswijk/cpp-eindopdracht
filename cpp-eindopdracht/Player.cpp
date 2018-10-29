#include "player.h"

Player::Player(const char* name) {
	this->name = name;
	this->exp_for_next_level = 200;
	this->level = 1;
	this->max_health = 100;
	this->current_health = this->max_health;
	this->attack = 50;
	this->defense = 20;
	this->exp = 0;
	this->equiped = nullptr;
}

const char* Player::to_string()
{
	return this->name;
}


Player::~Player() {
	delete[] name;
}
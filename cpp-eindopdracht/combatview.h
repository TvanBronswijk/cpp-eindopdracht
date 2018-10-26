#pragma once
#include "ptrarray.h"
#include "monster.h"
#include "view.h"
#include "gamecontext.h"

class CombatView : public View
{
private:
	const char* digits[10] = { "1", "2", "3", "4", "5", "6", "7", "8" , "8", "10"};
	PtrArray<Monster, 32>* monsters;
	int Rand(size_t min, size_t max);
	std::default_random_engine generator;
	bool checkMonstersHealth();
	void fight();
public:
	CombatView(GameContext* context, PtrArray<Monster, 32>* monsters);
	std::ostream& display() override;
	bool handle_input() override;
};
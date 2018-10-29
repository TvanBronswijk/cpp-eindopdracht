#pragma once
#include "ptrarray.h"
#include "monster.h"
#include "view.h"
#include "gamecontext.h"

class CombatView : public View
{
private:
	PtrArray<Monster, 32>* monsters;
	int Rand(size_t min, size_t max);
	std::default_random_engine generator;
	bool checkMonstersHealth();
	bool fight();
	bool run();
	bool drink_potion();
	bool equip_item();
	bool handle_input_equip_item(Player* player);
	bool handle_input(char c) override;
public:
	CombatView(GameContext* context, PtrArray<Monster, 32>* monsters);
	std::ostream& display() override;
};
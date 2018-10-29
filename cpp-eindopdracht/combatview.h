#pragma once
#include "ptrarray.h"
#include "monster.h"
#include "view.h"
#include "gamecontext.h"
#include "exitview.h"

class CombatView : public View
{
private:
	PtrArray<Monster, 8>* monsters;
	bool checkMonstersHealth();
	bool fight();
	bool run();
	bool drink_potion();
	bool equip_item();
	bool handle_input_equip_item(Player* player);
	bool handle_input(char c) override;
	void level_up();
public:
	CombatView(GameContext* context, PtrArray<Monster, 8>* monsters);
	std::ostream& display() override;
};
#pragma once
#include "ptrarray.h"
#include "monster.h"
#include "view.h"

class CombatView : public View
{
private:
	PtrArray<Monster, 32>* monsters;
public:
	CombatView(GameContext* context, PtrArray<Monster, 32>* monsters);
	std::ostream& display() override;
	bool handle_input() override;
};
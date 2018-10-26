#pragma once
#include "monster.h"
#include "view.h"

class CombatView : public View
{
private:
	Monster* monsters;
public:
	CombatView(GameContext& context, Monster* monsters);
	std::ostream& display() override;
	bool handle_input() override;
};
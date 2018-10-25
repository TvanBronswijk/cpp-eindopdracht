#pragma once

#include "view.h"

class CombatView : public View
{
public:
	CombatView(GameContext* context);
	std::ostream& display() override;
	bool handle_input() override;
};
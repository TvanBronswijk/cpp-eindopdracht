#pragma once

#include "view.h"

class CreditsView : public View
{
public:
	CreditsView(GameContext* context);
	std::ostream& display() override;
	bool handle_input() override;
};
#pragma once

#include "view.h"

class CreditsView : public View
{
private:
	bool handle_input(char c) override;
public:
	CreditsView(GameContext* context);
	std::ostream& display() override;
};
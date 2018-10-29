#pragma once
#include "view.h"

class SaveView : public View
{
private:
	bool handle_input(char c) override;
	bool yes();
	bool no();
public:
	SaveView(GameContext* context);
	std::ostream& display() override;
};
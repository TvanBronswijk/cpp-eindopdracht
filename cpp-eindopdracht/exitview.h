#pragma once
#include "view.h"
#include "mainview.h"

class ExitView : public View
{
private:
	bool handle_input(char c) override;
	bool yes();
	bool no();
	bool clear();
public:
	ExitView(GameContext* context);
	std::ostream& display() override;
};
#pragma once
#include "view.h"
#include "mainview.h"

class ExitView : public View
{
private:
	bool handle_input() override;
	bool handle_input(char c) override;
	bool clear();
public:
	ExitView(GameContext* context);
	std::ostream& display() override;
};
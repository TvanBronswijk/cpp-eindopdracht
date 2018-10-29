#pragma once
#include "view.h"
#include "mainview.h"

class ExitView : public View
{
private:
	bool handle_input(char c) override;
	const bool yes();
	const bool no();
	const bool clear();
public:
	ExitView(GameContext* context);
	std::ostream& display() override;
};
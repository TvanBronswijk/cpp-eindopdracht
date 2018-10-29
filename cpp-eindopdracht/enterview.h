#pragma once
#include "view.h"
#include "roomview.h"

class EnterView : public View
{
private:
	bool handle_input() override;
	bool handle_input(char c) override;
public:
	EnterView(GameContext* context);
	std::ostream& display() override;
};
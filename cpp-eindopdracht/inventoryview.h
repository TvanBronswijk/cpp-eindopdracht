#pragma once

#include "view.h"

class InventoryView : public View
{
private:
	bool handle_input(char c) override;
public:
	InventoryView(GameContext* context);
	std::ostream& display() override;
};
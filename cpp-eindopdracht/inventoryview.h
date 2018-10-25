#pragma once

#include "view.h"

class InventoryView : public View
{
public:
	InventoryView(GameContext* context);
	std::ostream& display() override;
	bool handle_input() override;
};
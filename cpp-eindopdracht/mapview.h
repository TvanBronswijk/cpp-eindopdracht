#pragma once

#include "view.h"

class MapView : public View
{
public:
	MapView(GameContext* context);
	std::ostream& display() override;
	bool handle_input() override;
};
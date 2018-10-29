#pragma once

#include "view.h"

class MapView : public View
{
private:
	bool handle_input(char c) override;
public:
	MapView(GameContext* context);
	std::ostream& display() override;
};
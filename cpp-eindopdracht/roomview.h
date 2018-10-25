#pragma once

#include "view.h"

class RoomView : public View
{
public:
	RoomView(GameContext* context);
	std::ostream& display() override;
	bool handle_input() override;
};
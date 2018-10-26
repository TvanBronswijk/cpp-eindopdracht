#pragma once
#include "room.h"
#include "view.h"

class RoomView : public View
{
private:
	Room* room;
public:
	RoomView(GameContext* context, Room* room);
	std::ostream& display() override;
	bool handle_input() override;
};
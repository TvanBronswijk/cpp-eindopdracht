#pragma once
#include "room.h"
#include "view.h"

class RoomView : public View
{
private:
	Room* room;
	void fight();
	void move();
	void search();
	void rest();
	void inventory();
	void dungeon();
	void character();
	void exit();
public:
	RoomView(GameContext* context, Room* room);
	std::ostream& display() override;
	bool handle_input() override;
};
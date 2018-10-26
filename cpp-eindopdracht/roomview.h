#pragma once
#include <random>
#include <ctime>
#include "room.h"
#include "view.h"
#include "characterview.h"
#include "combatview.h"
#include "inventoryview.h"
#include "mapview.h"

class RoomView : public View
{
private:
	std::default_random_engine generator;
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
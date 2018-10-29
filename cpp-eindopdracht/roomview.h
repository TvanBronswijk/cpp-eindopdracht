#pragma once
#include <random>
#include <ctime>
#include "room.h"
#include "view.h"
#include "characterview.h"
#include "combatview.h"
#include "inventoryview.h"
#include "mapview.h"
#include "exitview.h"
#include "saveview.h"

class RoomView : public View
{
private:
	Room* room;
	PtrArray<Monster, 8>* monsters;

	bool handle_input(char c) override;
	bool fight();
	bool move();
	bool search();
	bool rest();
	bool inventory();
	bool dungeon();
	bool character();
	bool go();
	bool exit();
public:
	RoomView(GameContext* context, Room* room);
	std::ostream& display() override;
	~RoomView();
};
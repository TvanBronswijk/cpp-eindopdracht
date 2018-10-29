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

class RoomView : public View
{
private:
	Room* room;
	PtrArray<Monster, 8>* monsters;

	bool handle_input(char c) override;
	const bool fight();
	const bool move();
	const bool search();
	const bool rest();
	const bool inventory();
	const bool dungeon();
	const bool character();
	const bool go();
	const bool exit();
public:
	RoomView(GameContext* context, Room* room);
	std::ostream& display() override;
	~RoomView();
};
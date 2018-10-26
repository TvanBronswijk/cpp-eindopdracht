#include "roomview.h"
#include "gamecontext.h"

RoomView::RoomView(GameContext* context, Room* room) : View(context)
{
	this->room = room;
}

std::ostream& RoomView::display()
{
	return std::cout
		<< this->room->to_string()
		<< std::endl
		<< "What do you want to do?"
		<< std::endl
		<< "[F]ight | [M]ove | [S]earch | [R]est | [I]nventory | [D]ungeon | [C]haracter | [E]xit"
		<< std::endl;
}

bool RoomView::handle_input()
{
	char a;
	std::cin >> a;

	switch (tolower(a)) {
	case 'f':
		fight();
		return true;
	case 'm':
		move();
		return true;
	case 's':
		search();
		return true;
	case 'r':
		rest();
		return true;
	case 'i':
		inventory();
		return true;
	case 'd':
		dungeon();
		return true;
	case 'c':
		character();
		return true;
	case 'e':
		exit();
		return true;
	}
	return false;
}

void RoomView::fight()
{
}

void RoomView::move()
{
}

void RoomView::search()
{
}

void RoomView::rest()
{
}

void RoomView::inventory()
{
}

void RoomView::dungeon()
{
}

void RoomView::character()
{
}

void RoomView::exit()
{
	context->gamestate->clear();
	back();
}

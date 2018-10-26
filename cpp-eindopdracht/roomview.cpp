#include "roomview.h"
#include "gamecontext.h"

RoomView::RoomView(GameContext* context, Room* room) : View(context)
{
	this->room = room;
}

std::ostream& RoomView::display()
{
	return std::cout << this->room->to_string() << std::endl;
}

bool RoomView::handle_input()
{
	char a;
	std::cin >> a;
	context->view_manager->pop();
	delete room;
	return true;
}

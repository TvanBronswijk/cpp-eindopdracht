#include "enterview.h"
#include "gamecontext.h"



EnterView::EnterView(GameContext * context) : View(context)
{
}

std::ostream & EnterView::display()
{
	return std::cout << "Welcome to The Dungeon!" << std::endl;
}

bool EnterView::handle_input()
{
	return context->view_manager->push(new RoomView(context, context->gamestate->get_dungeon()->find(Room::START)));
}

bool EnterView::handle_input(char c)
{
	throw -1;
}

#include "roomview.h"
#include "gamecontext.h"

RoomView::RoomView(GameContext * context) : View(context)
{
}

std::ostream & RoomView::display()
{
	return std::cout << "Hello World!";
}

bool RoomView::handle_input()
{
	char a;
	std::cin >> a;
	return false;
}

#include "mapview.h"

MapView::MapView(GameContext * context) : View(context)
{
}

std::ostream & MapView::display()
{
	return std::cout;
}

bool MapView::handle_input()
{
	char a;
	std::cin >> a;
	back();
	return true;
}

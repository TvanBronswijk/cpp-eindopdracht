#include "mapview.h"
#include "gamecontext.h"

MapView::MapView(GameContext * context) : View(context)
{
}

std::ostream & MapView::display()
{
	Dungeon* dungeon = this->context->gamestate->get_dungeon();
	for (size_t x = 0; x < dungeon->width(); x++) {
		for (size_t y = 0; y < dungeon->height(); y++) {
			std::cout << "X";
		}
		std::cout << std::endl;
	}

	return std::cout
		<< std::endl
		<< "[B]ack"
		<< std::endl;
}

bool MapView::handle_input()
{
	char a;
	std::cin >> a;

	if (tolower(a) == 'b') {
		back();
		return true;
	}
	else {
		return false;
	}
}

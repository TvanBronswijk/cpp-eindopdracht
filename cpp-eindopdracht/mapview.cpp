#include "mapview.h"
#include "gamecontext.h"

MapView::MapView(GameContext * context) : View(context)
{
}

std::ostream & MapView::display()
{
	Dungeon* dungeon = this->context->gamestate->get_dungeon();
	for (size_t y = 0; y < dungeon->height(); y++) {
		for (size_t x = 0; x < dungeon->width(); x++) {
			if (dungeon->coord(x, y)->visited)
				std::cout << "X";
			else
				std::cout << " ";

			if (dungeon->coord(x, y)->right != nullptr && (dungeon->coord(x, y)->visited || dungeon->coord(x, y)->right->visited))
				std::cout << "-";
			else
				std::cout << " ";
		}
		std::cout << std::endl;
		for (size_t x = 0; x < dungeon->width(); x++) {
			if (dungeon->coord(x, y)->up != nullptr && (dungeon->coord(x, y)->visited || dungeon->coord(x, y)->up->visited))
				std::cout << "| ";
			else
				std::cout << "  ";
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

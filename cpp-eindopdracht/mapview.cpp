#include "mapview.h"
#include "gamecontext.h"

MapView::MapView(GameContext * context) : View(context)
{
}

std::ostream & MapView::display()
{
	std::cout
		<< "THE DUNGEON"
		<< std::endl
		<< std::endl;

	Dungeon* dungeon = this->context->gamestate->get_dungeon();
	std::cout << "#";
	for (size_t i = 0; i < dungeon->width(); i++)
		std::cout << "##";
	std::cout << "#";
	std::cout << std::endl;
	for (size_t y = 0; y < dungeon->height(); y++) {
		std::cout << "#";
		for (size_t x = 0; x < dungeon->width(); x++) {
			if (dungeon->coord(x, y)->visited)
				std::cout << "X";
			else
				std::cout << ".";

			if (dungeon->coord(x, y)->right != nullptr && (dungeon->coord(x, y)->visited || dungeon->coord(x, y)->right->visited))
				std::cout << "-";
			else
				std::cout << " ";
		}
		std::cout << "#";
		std::cout << std::endl;
		std::cout << "#";
		for (size_t x = 0; x < dungeon->width(); x++) {
			if (dungeon->coord(x, y)->down != nullptr && (dungeon->coord(x, y)->visited || dungeon->coord(x, y)->down->visited))
				std::cout << "| ";
			else
				std::cout << "  ";
		}
		std::cout << "#";
		std::cout << std::endl;
	}
	std::cout << "#";
	for (size_t i = 0; i < dungeon->width(); i++)
		std::cout << "##";
	std::cout << "#";
	std::cout << std::endl;

	return std::cout
		<< std::endl
		<< "[B]ack"
		<< std::endl;
}

bool MapView::handle_input(char c)
{
	switch (tolower(c)) {
	case 'b':
		back();
		return true;
	}
	return false;
}

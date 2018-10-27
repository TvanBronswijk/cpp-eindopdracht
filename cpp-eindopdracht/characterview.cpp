#include "characterview.h"
#include "gamecontext.h"

CharacterView::CharacterView(GameContext * context) : View(context)
{

}

std::ostream & CharacterView::display()
{
	Player* player = this->context->gamestate->get_player();
	return std::cout
		<< "Hello, " << player->name << "!"
		<< std::endl
		<< "From your adventures you received " << player->exp << " exp, and became level " << player->level << "."
		<< std::endl
		<< std::endl
		<< "[B]ack"
		<< std::endl;
}

bool CharacterView::handle_input()
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

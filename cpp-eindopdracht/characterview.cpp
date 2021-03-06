#include "characterview.h"
#include "gamecontext.h"

CharacterView::CharacterView(GameContext * context) : View(context)
{

}

std::ostream & CharacterView::display()
{
	Player* player = this->context->gamestate->player;

	std::cout
		<< "Hello, " << player->name << "!"
		<< std::endl
		<< "From your adventures you received " << player->exp << " exp, and became level " << player->level << "."
		<< std::endl
		<< "You feel ";
	if (player->current_health > (player->max_health / 2))
		std::cout << "healthy." << std::endl;
	else
		std::cout << "hurt." << std::endl;

	return std::cout
		<< std::endl
		<< std::endl
		<< "[S]tats | [B]ack"
		<< std::endl;
}

bool CharacterView::handle_input(char c)
{
	switch (tolower(c)) {
	case 's':
		return stats();
	case 'b':
		return back();
	}
	return false;
}

bool CharacterView::stats()
{
	Player* player = this->context->gamestate->player;
	std::cout
		<< "Name:		" << player->name << std::endl
		<< "Experience:	" << player->exp << std::endl
		<< "Level:		" << player->level << std::endl
		<< "Health:		" << player->current_health << "/" << player->max_health << std::endl
		<< "Attack:		" << player->attack << std::endl
		<< "Defense:	" << player->defense << std::endl
		<< "Inventory:	" << player->items.size() << " items" << std::endl
		<< std:: endl;
	return true;
}

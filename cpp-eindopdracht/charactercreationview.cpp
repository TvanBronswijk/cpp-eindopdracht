#include "charactercreationview.h"


CharacterCreationView::CharacterCreationView(GameContext* context) : View(context)
{
}

std::ostream & CharacterCreationView::display()
{
	return std::cout << "what is your name?" << std::endl;
}

bool CharacterCreationView::handle_input()
{
	char name[35];
	std::cin >> name;
	this->context->gamestate->set_player(new Player(name)); // name gaat verkeerd.
	back();
	return true;
}

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
	char* name = new char[16];
	std::cin >> name;
	this->context->gamestate->set_player(new Player(name));
	back();
	return true;
}

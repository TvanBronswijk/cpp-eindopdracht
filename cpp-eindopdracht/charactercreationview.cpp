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
	for (int i = 0; i < 16; i++)
		name[i] = '\0';

	std::cin >> std::setw(17) >> name;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	for (int i = 0; i < 16; i++) {
		if (!(isalpha(name[i]) || name[i] == '\0')) {
			std::cout << "Name includes invalid characters. ";
			return false;
		}
	}
	this->context->gamestate->player = new Player(name);
	back();
	std::cout << "Welcome to The Dungeon!" << std::endl;
	return true;
}

bool CharacterCreationView::handle_input(char c)
{
	throw -1;
}

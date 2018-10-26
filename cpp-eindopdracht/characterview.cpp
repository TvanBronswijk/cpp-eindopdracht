#include "characterview.h"

CharacterView::CharacterView(GameContext * context) : View(context)
{

}

std::ostream & CharacterView::display()
{
	return std::cout;
}

bool CharacterView::handle_input()
{
	char a;
	std::cin >> a;
	back();
	return true;
}

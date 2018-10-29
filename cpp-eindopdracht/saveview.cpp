#include "saveview.h"
#include "gamecontext.h"


SaveView::SaveView(GameContext * context) : View(context)
{
}

std::ostream & SaveView::display()
{
	return std::cout
		<< "Do you wish to save?"
		<< std::endl
		<< "[Y]es/[N]o"
		<< std::endl;
}

bool SaveView::handle_input(char c)
{
	switch (tolower(c)) {
	case 'y':
		return yes();
	case 'n':
		return no();
	}
	return false;
}

bool SaveView::yes()
{
	context->save_manager->save(context->gamestate->player);
	return context->view_manager->pop();
}

bool SaveView::no()
{
	return context->view_manager->pop();
}

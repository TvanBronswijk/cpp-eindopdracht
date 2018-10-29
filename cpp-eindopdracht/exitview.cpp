#include "exitview.h"
#include "gamecontext.h"


ExitView::ExitView(GameContext * context) : View(context)
{
}

std::ostream & ExitView::display()
{
	return std::cout
		<< "Do you wish to save?"
		<< std::endl
		<< "[Y]es/[N]o"
		<< std::endl;
}

bool ExitView::handle_input(char c)
{
	switch (tolower(c)) {
	case 'y':
		return yes();
	case 'n':
		return no();
	}
	return false;
}

bool ExitView::yes()
{
	//TODO

	return clear();
}

bool ExitView::no()
{
	return clear();
}

bool ExitView::clear()
{
	GameContext* context = this->context;
	while (!context->view_manager->is_empty())
		context->view_manager->pop();

	delete context->gamestate;
	context->gamestate = nullptr;
	return context->view_manager->push(new MainView(context));
}

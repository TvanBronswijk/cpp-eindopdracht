#include "exitview.h"
#include "gamecontext.h"


ExitView::ExitView(GameContext * context) : View(context)
{
}

std::ostream & ExitView::display()
{
	return std::cout;
}

bool ExitView::handle_input() 
{
	return clear();
}

bool ExitView::handle_input(char c)
{
	throw - 1;
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

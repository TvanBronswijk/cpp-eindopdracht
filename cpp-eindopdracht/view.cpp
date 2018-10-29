#include "view.h"
#include "gamecontext.h"

View::View(GameContext* context)
{
	this->context = context;
}

bool View::handle_input()
{
	char a;
	std::cin >> a;
	return handle_input(a);
}

bool View::back()
{
	return this->context->view_manager->pop();
}

View::~View()
{
}

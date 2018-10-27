#include "view.h"
#include "gamecontext.h"

View::View(GameContext* context)
{
	this->context = context;
}

View::~View()
{
}

bool View::back()
{
	return this->context->view_manager->pop();
}

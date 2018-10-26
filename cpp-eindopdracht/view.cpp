#include "view.h"
#include "gamecontext.h"

View::View(GameContext* context)
{
	this->context = context;
}

void View::back()
{
	this->context->view_manager->pop();
}

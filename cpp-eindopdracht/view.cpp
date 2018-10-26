#include "view.h"
#include "gamecontext.h"

View::View(GameContext* context)
{
	this->context = context;
}

View::~View()
{
}

void View::back()
{
	this->context->view_manager->pop();
}

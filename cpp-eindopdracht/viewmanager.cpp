#include "viewmanager.h"

ViewManager::ViewManager()
{

}

View * ViewManager::current()
{
	return view_stack.peek();
}


void ViewManager::pop()
{
	delete view_stack.pop();
}

void ViewManager::push(View* v)
{
	view_stack.push(v);
}

void ViewManager::display()
{
	if (view_stack.size() > 0)
		view_stack.peek()->display();
}

void ViewManager::display(View* v)
{
	this->push(v);
	this->display();
}

bool ViewManager::handle_input()
{
	return view_stack.peek()->handle_input();
}

bool ViewManager::is_empty()
{
	return view_stack.size() == 0;
}

ViewManager::~ViewManager()
{

}

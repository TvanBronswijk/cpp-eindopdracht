#include "viewmanager.h"

ViewManager::ViewManager()
{

}

View* ViewManager::current()
{
	try {
		return view_stack.peek();
	}
	catch (int e) {
		std::cout << "ERROR " << e << " : No views in the view stack." << std::endl;
		return nullptr;
	}
}

bool ViewManager::push(View* v)
{
	try {
		view_stack.push(v);
		return true;
	}
	catch (int e) {
		std::cout << "ERROR " << e << " : The view stack reached it limit." << std::endl;
		return false;
	}
}

bool ViewManager::pop()
{
	try {
		delete view_stack.pop();
		return true;
	}
	catch (int e) {
		std::cout << "ERROR " << e << " : You're trying to pop an empty view stack." << std::endl;
		return false;
	}
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
	if (view_stack.size() > 0)
		return view_stack.peek()->handle_input();
	else
		return true;
}

bool ViewManager::is_empty()
{
	return view_stack.size() == 0;
}

ViewManager::~ViewManager()
{

}

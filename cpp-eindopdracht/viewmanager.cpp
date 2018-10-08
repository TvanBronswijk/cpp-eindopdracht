#include "ViewManager.h"

ViewManager::ViewManager()
{
	this->_current = 0;
	view_stack = new View*[32];
}

View* ViewManager::current()
{
	return view_stack[this->_current];
}

View* ViewManager::pop()
{
	if (this->_current > 0)
	{
		auto v = view_stack[this->_current];
		this->_current--;
		return v;
	}
	else
	{
		throw -1;
	}
}

void ViewManager::push(View* v)
{
	if (this->_current < MAX_VIEWS) 
	{
		this->_current++;
		view_stack[this->_current] = v;
	}
	else 
	{
		throw -1;
	}
}

void ViewManager::display() 
{
	view_stack[this->_current]->display();
}

void ViewManager::display(View* v)
{
	this->push(v);
	this->display();
}

void ViewManager::clear()
{
	//TODO
}

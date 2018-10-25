#include "viewmanager.h"

ViewManager::ViewManager()
{
	this->_size = 0;
	this->_current = -1;
	view_stack = new View*[MAX_VIEWS];
}

View* ViewManager::current()
{
	return view_stack[this->_current];
}

View* ViewManager::pop()
{
	if (this->_current >= 0)
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

		if (_current > _size)
			_size = _current;
	}
	else 
	{
		throw -1;
	}
}

void ViewManager::display()
{
	if (_current >= 0)
		view_stack[this->_current]->display();
}

void ViewManager::display(View* v)
{
	this->push(v);
	this->display();
}

bool ViewManager::handle_input()
{
	return view_stack[this->_current]->handle_input();
}

bool ViewManager::is_empty()
{
	return _current < 0;
}

ViewManager::~ViewManager()
{
	for (int i = 0; i <= _size; i++)
		delete view_stack[i];
	delete[] view_stack;
}

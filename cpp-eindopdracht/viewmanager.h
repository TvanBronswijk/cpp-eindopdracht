#pragma once
#include "view.h"
#include "stack.h"

class ViewManager
{
private:
	Stack<View, 32> view_stack;
public:
	ViewManager();
	View*& current();
	bool pop();
	bool push(View* v);
	void display();
	void display(View* v);
	bool handle_input();
	bool is_empty();
	~ViewManager();
};
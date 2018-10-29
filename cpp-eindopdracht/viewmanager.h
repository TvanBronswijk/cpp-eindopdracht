#pragma once
#include <iostream>
#include "view.h"
#include "stack.h"

class ViewManager
{
private:
	Stack<View, 32> view_stack;
public:
	ViewManager();
	View* current();
	bool pop();
	bool push(View* v);
	std::ostream& display();
	std::ostream& display(View* v);
	bool handle_input();
	bool is_empty();
	~ViewManager();
};
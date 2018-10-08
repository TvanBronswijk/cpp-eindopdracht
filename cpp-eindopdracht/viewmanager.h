#pragma once
#include "view.h"

class ViewManager
{
private:
	const static int MAX_VIEWS = 32;
	int _current;
	View** view_stack;
public:
	ViewManager();
	View* current();
	View* pop();
	void push(View* v);
	void display();
	void display(View* v);
	void clear();
};
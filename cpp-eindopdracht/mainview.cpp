#include "mainview.h"
#include "gamecontext.h"

MainView::MainView(GameContext* context) : View(context)
{
}

std::ostream& MainView::display()
{
	return std::cout 
		<< "Hello, and welcome to Kerkers & Draken! Would you like to start a new game?"
		<< "[Y]es/[N]o?"
		<< std::endl;
}

bool MainView::handle_input()
{
	char a;
	std::cin >> a;

	switch (tolower(a)) {
	case 'y':
		context->view_manager->push(new RoomView(context));
		return true;
	case 'n':
		context->view_manager->pop();
		return true;
	}
	return false;
}

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
		yes();
		return true;
	case 'n':
		no();
		return true;
	}
	return false;
}

void MainView::yes()
{
	std::cout << "Welcome to The Dungeon!" << std::endl;
	context->gamestate->set_dungeon(context->dungeon_generator->Generate(10, 10));
	context->view_manager->push(new RoomView(context, context->gamestate->get_dungeon()->coord(1, 1)));
}

void MainView::no()
{
	context->view_manager->pop();
}

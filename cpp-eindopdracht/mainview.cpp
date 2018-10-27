#include "mainview.h"
#include "gamecontext.h"

MainView::MainView(GameContext* context) : View(context)
{
}

std::ostream& MainView::display()
{
	return std::cout
		<< "Hello, and welcome to Kerkers & Draken! Would you like to start a new game?"
		<< std::endl
		<< "[Y]es/[N]o?"
		<< std::endl;
}

bool MainView::handle_input()
{
	char a;
	std::cin >> a;

	switch (tolower(a)) {
	case 'y':
		return yes();
	case 'n':
		return no();
	case 'c':
		return credits();
	}
	return false;
}

bool MainView::yes()
{
	std::cout << "Welcome to The Dungeon!" << std::endl;
	context->gamestate->set_dungeon(context->dungeon_generator->Generate(8, 8));

	Room* room = context->gamestate->get_dungeon()->coord(1, 1);
	context->view_manager->push(new RoomView(context, room));
	room->visited = true;
	return context->view_manager->push(new CharacterCreationView(context));
}

bool MainView::no()
{
	return back();
}

bool MainView::credits()
{
	return context->view_manager->push(new CreditsView(context));
}

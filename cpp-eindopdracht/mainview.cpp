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

bool MainView::handle_input(char c)
{
	switch (tolower(c)) {
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
	context->gamestate = new GameState();
	return context->view_manager->push(new CharacterCreationView(context))
		&& context->view_manager->push(new DungeonCreationView(context));
}

bool MainView::no()
{
	return back();
}

bool MainView::credits()
{
	return context->view_manager->push(new CreditsView(context));
}

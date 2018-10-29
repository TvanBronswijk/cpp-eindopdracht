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
		<< "[Y]es/[L]oad/[N]o?"
		<< std::endl;
}

bool MainView::handle_input(char c)
{
	switch (tolower(c)) {
	case 'y':
		return yes();
	case 'l':
		return load();
	case 'n':
		return no();
	case 'c':
		return credits();
	}
	return false;
}

const bool MainView::yes()
{
	context->gamestate = new GameState();
	return context->view_manager->push(new EnterView(context))
		&& context->view_manager->push(new CharacterCreationView(context))
		&& context->view_manager->push(new DungeonCreationView(context));
}

const bool MainView::load()
{
	context->gamestate = new GameState();
	context->save_manager->print();

	int i;
	
	while (!(std::cin >> i))
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	try {
		context->gamestate->player = context->save_manager->load_save(i);
		return context->view_manager->push(new EnterView(context))
			&& context->view_manager->push(new DungeonCreationView(context));
	}
	catch (int e) {
		std::cout << "Incorrect save.";
		return false;
	}
}

const bool MainView::no()
{
	return back();
}

const bool MainView::credits()
{
	return context->view_manager->push(new CreditsView(context));
}
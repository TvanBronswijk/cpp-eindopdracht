#include "mainview.h"
#include "roombuilder.h"
#include "player.h"

MainView::MainView(GameContext * context) : View(context)
{
}

void MainView::display()
{
	std::cout << "Hello World!" << std::endl;
}

void MainView::handle_input()
{
	char c;
	std::cin >> c;
}

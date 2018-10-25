#include "mainview.h"

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

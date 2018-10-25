#include "mainview.h"
#include "gamemanager.h"

MainView::MainView(GameContext * context) : View(context)
{
	this->context = context;
}

void MainView::display()
{
	std::cout << "Hello, do i know you?(yes/no)" << std::endl;

}

void MainView::handle_input()
{
	char answer[4];

	std::cin.getline(answer, 4);

	if (strcmp(answer, "yes") == 0){
		context->gamestate->push(new Player("rick"));
		context->gamestate->push(new Player("jos"));
		Player** players = context->gamestate->getallPlayers();
		int size = context->gamestate->getamountofplayers();
		for (int i = 0; i <= size; i++) {
			std::cout << "hmmm are you: " << players[i]->_name << " (yes/no)" << std::endl;
			char answer[4];
			std::cin.getline(answer, 4);
			if (strcmp(answer, "yes") == 0) return; // new view pushen
		}
	}
	std::cout << "Hello Stranger!, you are entering our dungeon. What is your name?" << std::endl;
	char name[35];

	std::cin.getline(name, 35);
	context->gamestate->push(new Player(name));
	std::cout << "Hello "<< context->gamestate->getPlayer(name)->_name <<"! get inside and prepare to dead!!!!!" << std::endl;
	// new view pushen
}

#include "dungeoncreationview.h"
#include "gamecontext.h"

DungeonCreationView::DungeonCreationView(GameContext* context) : View(context)
{
}

std::ostream & DungeonCreationView::display()
{
	return std::cout << "How large should the dungeon be? [3-10]" << std::endl;
}

bool DungeonCreationView::handle_input()
{
	int scale;
	while (!(std::cin >> scale)) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	if (scale < 3)
		scale = 3;
	if (scale > 10)
		scale = 10;

	GameConfig* config = new GameConfig(scale, scale * 1.5, scale);
	context->gamestate->config = config;
	for (size_t i = 0; i < config->depth(); i++)
		context->gamestate->dungeons.push(context->dungeon_generator->generate(config, i));

	return back();
}

bool DungeonCreationView::handle_input(char c)
{
	throw - 1;
}

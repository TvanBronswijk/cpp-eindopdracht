#include "gamecontext.h"

GameContext::GameContext()
{
	view_manager = new ViewManager();

	item_generator = new ItemGenerator();
	monster_generator = new MonsterGenerator();
	room_generator = new RoomGenerator(item_generator);
	dungeon_generator = new DungeonGenerator(room_generator);

	gamestate = nullptr;
}

GameContext::~GameContext()
{
	delete view_manager;
	delete item_generator;
	delete monster_generator;
	delete room_generator;
	delete dungeon_generator;
	delete gamestate;

}

#include "inventoryview.h"
#include "gamecontext.h"

InventoryView::InventoryView(GameContext * context) : View(context)
{
}

std::ostream & InventoryView::display()
{
	Player* player = this->context->gamestate->get_player();

	for (int i = 0; i < player->items.size(); i++)
		std::cout 
		<< i << ": " << player->items.get(i)->to_string()
		<< std::endl;

	if (player->items.size() <= 0)
		std::cout 
		<< "No items in your inventory." 
		<< std::endl;

	return std::cout
		<< std::endl
		<< "[B]ack"
		<< std::endl;
}

bool InventoryView::handle_input()
{
	char a;
	std::cin >> a;

	if (tolower(a) == 'b') {
		back();
		return true;
	}
	else {
		return false;
	}
}

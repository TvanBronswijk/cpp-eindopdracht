#include "inventoryview.h"

InventoryView::InventoryView(GameContext * context) : View(context)
{
}

std::ostream & InventoryView::display()
{
	return std::cout;
}

bool InventoryView::handle_input()
{
	char a;
	std::cin >> a;
	back();
	return true;
}

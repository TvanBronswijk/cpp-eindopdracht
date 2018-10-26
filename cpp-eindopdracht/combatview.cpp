#include "combatview.h"

CombatView::CombatView(GameContext* context, PtrArray<Monster, 32>* monsters) : View(context)
{
	this->monsters = monsters;
}

std::ostream & CombatView::display()
{
	return std::cout;
}

bool CombatView::handle_input()
{
	char a;
	std::cin >> a;
	back();
	return true;
}

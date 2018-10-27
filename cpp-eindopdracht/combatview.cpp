#include "combatview.h"

CombatView::CombatView(GameContext* context, PtrArray<Monster, 32>* monsters) : View(context)
{
	this->monsters = monsters;
	generator.seed(time(0));
}

int CombatView::Rand(size_t min, size_t max)
{
	std::uniform_int_distribution<int> d(min, max);
	return d(generator);
}

bool CombatView::checkMonstersHealth() {
	for (size_t i = 0; i < monsters->size(); i++) {
		Monster* monster = monsters->get(i);
		if (monster->hp > 0) {
			return false;
		}
	}
	return true;
}

std::ostream & CombatView::display()
{
	if (monsters->size() > 0) {
		char text[3000] = "";
		strcat_s(text, "you are fighting against: \r\n");
		for (size_t i = 0; i < monsters->size(); i++) {
			Monster* monster = monsters->get(i);
			strcat_s(text, digits[i]);
			strcat_s(text, ": ");
			strcat_s(text, monster->name);
			strcat_s(text, "\r\n");
		}
		strcat_s(text, "\r\n");
		strcat_s(text, "Actions off the enemy: \r\n");
		for (size_t i = 0; i < monsters->size(); i++) {
			Monster* monster = monsters->get(i);
			strcat_s(text, digits[i]);
			strcat_s(text, ": ");
			strcat_s(text, monster->name);
			if (Rand(0, 99) <= monster->hitchance) {
				strcat_s(text, " did ");
				strcat_s(text, digits[Rand(0, 2)]);
				strcat_s(text, " damage! \r\n");
			}else
			strcat_s(text, "did no damage. \r\n");
		}
		strcat_s(text, "\r\n");
		strcat_s(text, "What will you do? \r\n");
		strcat_s(text, "[F]ight | [R]un | [D]rink potion | [I]nventory \r\n");

		return std::cout << text;
	}
	back();
	return std::cout << "there are no monsters";
}

bool CombatView::handle_input()
{
	char a;
	std::cin >> a;

	switch (tolower(a)) {
	case 'f':
		fight();
		return true;
	case 'r':
		return true;
	case 'd':
		return true;
	case 'i':
		return true;
	}
	back();
	return false;
}

void CombatView::fight() {
	char text[3000] = "";

	for (size_t i = 0; i < monsters->size(); i++) {
		Monster* monster = monsters->get(i);
		strcat_s(text, digits[i]);
		strcat_s(text, ": ");
		strcat_s(text, monster->name);
		strcat_s(text, " has taken ");
		if (Rand(0, 10) <= context->gamestate->get_player()->attack) {
			strcat_s(text, digits[Rand(1, 3)]);
			strcat_s(text, " damage! \r\n");
		}
		else
			strcat_s(text, " no damage. \r\n");
	}

	if (checkMonstersHealth()) {
		strcat_s(text, "you have defeated the monsters \r\n");
		back();
		std::cout << text;
	}
	std::cout << text;
}

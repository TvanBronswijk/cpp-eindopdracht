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
	Player* player = context->gamestate->get_player();
	if (monsters->size() > 0) {
		std::cout << "you are fighting against: \r\n";
		for (size_t i = 0; i < monsters->size(); i++) {
			Monster* monster = monsters->get(i);
			std::cout << digits[i] << ": " << monster->name << " With " << monster->hp << " health. \r\n";
		}
		std::cout << "\r\n" << "Actions off the enemy: \r\n";
		for (size_t i = 0; i < monsters->size(); i++) {
			Monster* monster = monsters->get(i);
			std::cout << digits[i] << ": " << monster->name;
			if (Rand(0, 99) <= monster->hitchance) {
				int rand = Rand(monster->min_damage, monster->max_damage);
				std::cout << " did " << digits[rand] << " damage! \r\n";
				player->current_health -= rand;
			}
			else
				std::cout << " did no damage. \r\n";
		}
		std::cout << "\r\n" << "Your current health is " << player->current_health;
		std::cout << "\r\nWhat will you do ? \r\n";
		std::cout << "[F]ight | [R]un | [D]rink potion | [I]nventory \r\n";

		return std::cout;
	}
	back();
	return std::cout << "there are no monsters";
}

bool CombatView::handle_input(char c)
{
	switch (tolower(c)) {
	case 'f':
		return fight();
	case 'r':
		return run();
	case 'd':
		return drink_potion();
	case 'i':
		return equip_item();
	}
	return false;
}

bool CombatView::fight() {
	Player* player = context->gamestate->get_player();

	for (size_t i = 0; i < monsters->size(); i++) {
		Monster* monster = monsters->get(i);
		std::cout << digits[i] << ": " << monster->name << " has taken ";
		if (Rand(0, 99) <= player->attack) {
			int rand;
			int max_damage;

			if (player->equiped == nullptr) max_damage = 3;
			else max_damage = player->equiped->get_int();
			rand = Rand(1, max_damage);
			std::cout << digits[rand] << " damage! \r\n";
			monster->hp -= rand;
		}
		else
			std::cout << "no damage. \r\n";
	}

	if (checkMonstersHealth()) {
		std::cout << "you have defeated the monsters \r\n";
		back();
	}

	return true;
}

bool CombatView::run(){
	std::cout << "You are running away from the monsters.";
	back();
	return true;
}


bool CombatView::drink_potion(){
	Player* player = context->gamestate->get_player();
	if (player->potions.size() > 0) {
		player->current_health += player->potions.get(player->potions.size())->get_int();
		player->potions.get(player->potions.size()) = nullptr;
		std::cout << "You have drunk a potion. \r\n" << "You have: " << player->potions.size() << " left.";

	}else
		std::cout << "There are no potions!" ;

	return true;
}

bool CombatView::handle_input_equip_item(Player* player) {
	char a;
	std::cin >> a;

	for (size_t i = 0; i < 10; i++) {
		if (a == digits[i][1])
			player->equiped = player->items.get(i);
		else 
			return false;
	}
	return true;
}

bool CombatView::equip_item(){
	Player* player = context->gamestate->get_player();
	std::cout << "\r\n \r\n" << "Your selected item is: ";
	if (player->equiped == nullptr) {
		std::cout << "nothing.";
	}else
		std::cout << player->equiped->to_string();
	std::cout << "\r\n \r\n";
	if (player->items.size() > 0) {
		for (size_t i = 0; i < player->items.size(); i++) {
			std::cout << digits[i] << ": " << player->items.get(i)->to_string() << " | ";
		}
		std::cout << "\r\n \r\n" << "Select with item you want. (#)";
		while (!handle_input_equip_item(player)) {
			std::cout << "Wrong input. \r\n \r\n";
		}

		return true;
	}
	std::cout << "You do not have any items.";
	return true;
}

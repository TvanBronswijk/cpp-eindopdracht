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
	Player* player = context->gamestate->player;
	if (monsters->size() > 0) {
		std::cout 
			<< "you are fighting against:" 
			<< std::endl;
		for (size_t i = 0; i < monsters->size(); i++) {
			Monster* monster = monsters->get(i);
			if (monster->hp > 0) {
				std::cout
					<< i << ": " << monster->name << " With " << monster->hp << " health."
					<< std::endl;
			}
		}
		std::cout 
			<< std::endl 
			<< "Actions off the enemy:" 
			<< std::endl;
		for (size_t i = 0; i < monsters->size(); i++) {
			Monster* monster = monsters->get(i);
			if (monster->hp > 0) {
				std::cout
					<< i << ": " << monster->name;
				if (Rand(0, 99) <= monster->hitchance) {
					int rand = Rand(monster->min_damage, monster->max_damage);
					std::cout
						<< " did " << rand << " damage!"
						<< std::endl;
					player->current_health -= rand;
				}
				else
					std::cout
					<< " did no damage."
					<< std::endl;
			}
		}
		std::cout 
			<< std::endl 
			<< "Your current health is " << player->current_health;
		std::cout 
			<< std::endl 
			<< "What will you do ? " 
			<< std::endl;
		std::cout 
			<< "[F]ight | [R]un | [D]rink potion | [I]nventory " 
			<< std::endl;

		return std::cout;
	}
	return std::cout 
		<< "there are no monsters. [B]ack"
		<< std::endl;
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
	case 'b':
		return back();
	}
	return false;
}

bool CombatView::fight() {
	Player* player = context->gamestate->player;

	for (size_t i = 0; i < monsters->size(); i++) {
		Monster* monster = monsters->get(i);
		if (monster->hp > 0) {
			std::cout
				<< i << ": " << monster->name << " has taken ";
			if (Rand(0, 99) <= player->attack) {
				int rand;
				int max_damage;

				if (player->equiped == nullptr) max_damage = 3;
				else max_damage = player->equiped->get_int();
				rand = Rand(1, max_damage);
				std::cout
					<< rand << " damage! "
					<< std::endl;
				monster->hp -= rand;
			}
			else
				std::cout
				<< "no damage. "
				<< std::endl;
		}
	}

	if (checkMonstersHealth()) {
		std::cout 
			<< "you have defeated the monsters " 
			<< std::endl;
		delete monsters;
		monsters = nullptr;

		back();
	}

	return true;
}

bool CombatView::run(){
	std::cout << "You are running away from the monsters.";
	return 	back();
}


bool CombatView::drink_potion(){
	Player* player = context->gamestate->player;
	if (player->potions.size() > 0) {
		player->current_health += player->potions.get(player->potions.size())->get_int();
		player->potions.get(player->potions.size()) = nullptr;
		std::cout 
			<< "You have drunk a potion." 
			<< std::endl 
			<< "You have: " << player->potions.size() << " left.";

	}else
		std::cout 
			<< "There are no potions!" ;

	return true;
}

bool CombatView::handle_input_equip_item(Player* player) { //TODO: reapeat error
	int a;
	std::cin >> a;
	char* digit;
	if (player->items.get(a) != nullptr) {
		player->equiped = player->items.get(a);
		return true;
	}
		else 
			return false;
}

bool CombatView::equip_item(){
	Player* player = context->gamestate->get_player();
	std::cout 
		<< std::endl 
		<< std::endl 
		<< "Your selected item is:";
	if (player->equiped == nullptr) {
		std::cout 
			<< "nothing.";
	}else
		std::cout 
		<< player->equiped->to_string();
		std::cout 
			<< std::endl 
			<< std::endl;
	if (player->items.size() > 0) {
		for (size_t i = 0; i < player->items.size(); i++) {
			std::cout 
				<< i << ": " << player->items.get(i)->to_string() << " | ";
		}
		std::cout 
			<< std::endl 
			<< std::endl 
			<< "Select with item you want. (#)";
		while (!handle_input_equip_item(player)) {
			std::cout 
				<< "Wrong input." 
				<< std::endl 
				<< std::endl;
		}

		return true;
	}
	std::cout << "You do not have any items.";
	return true;
}

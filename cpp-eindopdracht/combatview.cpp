#include "combatview.h"

CombatView::CombatView(GameContext* context, PtrArray<Monster, 8>* monsters) : View(context)
{
	this->monsters = monsters;
}

std::ostream & CombatView::display()
{
	Player* player = context->gamestate->player;
	if (monsters != nullptr) {
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
	Player* player = context->gamestate->player;
	if (player->current_health <= 0) {
		delete monsters;
		return context->view_manager->push(new ExitView(context));
	}
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

	std::cout
		<< std::endl
		<< "Actions off the enemy:"
		<< std::endl;
	for (size_t i = 0; i < monsters->size(); i++) {
		Monster* monster = monsters->get(i);
		if (monster->hp > 0) {
			std::cout
				<< i << ": " << monster->name;
			if (context->random->get(0, 99) <= monster->hitchance && context->random->get(0, 99) >= player->defense) {
				int rand = context->random->get(monster->min_damage, monster->max_damage);
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

	for (size_t i = 0; i < monsters->size(); i++) {
		Monster* monster = monsters->get(i);
		if (monster->hp > 0) {
			std::cout
				<< i << ": " << monster->name << " has taken ";
			if (context->random->get(0, 99) <= player->attack) {
				int rand;
				int max_damage;

				if (player->equiped == nullptr) 
					max_damage = player->level;
				else max_damage = player->equiped->get_value() + player->level;
				rand = context->random->get(1, max_damage);
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
		
		level_up();

		delete monsters;
		back();
	}

	return true;
}

bool CombatView::run(){
	std::cout << "You are running away from the monsters.";
	delete monsters;
	return 	back();
}


bool CombatView::drink_potion(){
	Player* player = context->gamestate->player;
	if (player->potions.size() > 0) {
		player->current_health += player->potions.get(player->potions.size() -1)->get_value();
		if (player->current_health > player->max_health) player->current_health = player->max_health;
		player->potions.remove(player->potions.size() - 1);
		std::cout 
			<< "You have drunk a potion." 
			<< std::endl 
			<< "You have: " << player->potions.size() << " left.";

	}else
		std::cout 
			<< "There are no potions!" ;

	return true;
}

bool CombatView::handle_input_equip_item(Player* player) {
	int a;

	while (!(std::cin >> a)) {
		std::cin.clear();
		std::cout << "wrong input";
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	try{
		player->equiped = player->items.get(a);
		return true;
	}
	catch(int e) {
		return false;
	}
}

void CombatView::level_up() {
	Player* player = context->gamestate->player;

	player->exp += (monsters->size() * 50);
	while (player->exp > player->exp_for_next_level) {
		int exp = player->exp - player->exp_for_next_level;
		player->exp = exp;
		player->level += 1;
		player->attack += 2;
		player->defense += 3;
		player->max_health += 5;
		std::cout
			<< "congratulations you have reached level "
			<< player->level
			<< "!!"
			<< std::endl;
	}
}

bool CombatView::equip_item(){
	Player* player = context->gamestate->player;
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
			<< "Select with item you want. (#)"
			<< std::endl;
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

bool CombatView::checkMonstersHealth() {
	for (size_t i = 0; i < monsters->size(); i++) {
		Monster* monster = monsters->get(i);
		if (monster->hp > 0) {
			return false;
		}
	}

	if (monsters->get(0)->level >= 99) {
		delete monsters;
		return context->view_manager->push(new ExitView(context)) && context->view_manager->push(new SaveView(context));
	}

	return true;
}

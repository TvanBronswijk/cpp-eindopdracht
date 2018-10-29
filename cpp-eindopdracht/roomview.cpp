#include "roomview.h"
#include "gamecontext.h"

RoomView::RoomView(GameContext* context, Room* room) : View(context)
{
	this->room = room;
	this->room->visited = true;
}

std::ostream& RoomView::display()
{
	std::cout
		<< this->room->to_string()
		<< std::endl;

	if (room->up != nullptr)
		std::cout
		<< "Up: " << room->up->hallway()
		<< std::endl;
	if (room->down != nullptr)
		std::cout
		<< "Down: " << room->down->hallway()
		<< std::endl;
	if (room->left != nullptr)
		std::cout
		<< "Left: " << room->left->hallway()
		<< std::endl;
	if (room->right != nullptr)
		std::cout
		<< "Right: " << room->right->hallway()
		<< std::endl;


	if (this->monsters != nullptr && this->monsters->size() > 0) {//TODO: error on monsters
		std::cout << "In the room you find a ";
		for (size_t i = 0; i < this->monsters->size(); i++) {
			std::cout << this->monsters->get(i)->name;
			if (i != this->monsters->size()-1)
				std::cout << ", a ";
		}
		std::cout << "." << std::endl;
	}
	else 
		std::cout << "there are no monsters in this room." << std::endl;

	if (room->type == Room::DOWN)
		std::cout << "There's a stairwell leading downwards..." << std::endl;
	else if (room->type == Room::UP)
		std::cout << "A stair is winds back up." << std::endl;
	
	std::cout
		 << "What do you want to do?"
		 << std::endl;

	if (room->type == Room::DOWN)
		std::cout << "[G]o Down | ";
	else if (room->type == Room::UP)
		std::cout << "[G]o Up | ";
	return std::cout 
		<< "[F]ight | [M]ove | [S]earch | [R]est | [I]nventory | [D]ungeon | [C]haracter | [E]xit"
		<< std::endl;
}

bool RoomView::handle_input(char c)
{
	switch (tolower(c)) {
	case 'f':
		return fight();
	case 'm':
		return move();
	case 's':
		return search();
	case 'r':
		return rest();
	case 'i':
		return inventory();
	case 'd':
		return dungeon();
	case 'c':
		return character();
	case 'g':
		return go();
	case 'e':
		return exit();
	}
	return false;
}

const bool RoomView::fight()
{

	PtrArray<Monster, 8>* monsters = this->monsters;
	if (monsters == nullptr) { return false; }
	this->monsters = nullptr;
	return context->view_manager->push(new CombatView(context, monsters));
}

const bool RoomView::move()
{
	if (monsters != nullptr) {
		delete monsters;
		monsters = nullptr;
	}

	std::cout
		<< std::endl
		<< "Which direction do you want to go?"
		<< std::endl;
	if (room->up != nullptr)
		std::cout << "| [U]p |";
	if (room->down != nullptr)
		std::cout << "| [D]own |";
	if (room->left != nullptr)
		std::cout << "| [L]eft |";
	if (room->right != nullptr)
		std::cout << "| [R]ight |";
	std::cout << std::endl;
	
	char a;
	std::cin >> a;

	Room* target;
	switch (tolower(a)) {
	case 'u':
		target = room->up;
		break;
	case 'd':
		target = room->down;
		break;
	case 'l':
		target = room->left;
		break;
	case 'r':
		target = room->right;
		break;
	default:
		target = nullptr;
		break;
	}

	if (target != nullptr) {
		int amount_of_monster = context->random->get(0, 5);
		if(amount_of_monster != 0){
			monsters = new PtrArray<Monster,8>();
			for (size_t i = 0; i < amount_of_monster; i++) {
				monsters->push(this->context->monster_generator->generate(context->gamestate->current_depth+1, context->gamestate->current_depth + 3));
			}
		}

		this->room = target;
		target->visited = true;
		return true;
	}
	else {
		std::cout 
			<< "That's not a valid direction." 
			<< std::endl;
		return true;
	}
}

const bool RoomView::search()
{
	if (this->room->item != nullptr) {
		std::cout
			<< "you have found a "
			<< this->room->item->get_details()
			<< std::endl
			<< "Do you want to pick it up?"
			<< std::endl
			<< "[Y]es/[N]o"
			<< std::endl;

		char a;
		std::cin >> a;

		switch (tolower(a)) {
		case 'y':
			if (Weapon* weapon = dynamic_cast<Weapon*>(room->item)) {
				this->context->gamestate->player->items.push(room->item); //TODO: afvangen wanneer vol is.
			}else
			this->context->gamestate->player->potions.push(room->item); //TODO: afvangen wanneer vol is.
			room->item = nullptr;
			return true;
			break;
		case 'n':
			return true;
		default:
			return false;
			break;
		}
	}
	else { std::cout << "There is no item."; return true; }
}

const bool RoomView::rest()
{
	std::cout 
		<< "resting..." 
		<< std::endl;

	if (context->random->get(0,10) == 0) {
		int amount_of_monsters = context->random->get(1,5);
		PtrArray<Monster, 8>* monsters = new PtrArray<Monster, 8>();
		for (int i = monsters->size(); i < amount_of_monsters; i++)
			monsters->push(context->monster_generator->generate(1, context->gamestate->current_depth + 3));
		
		std::cout
			<< "You were ambushed by "
			<< monsters->size()
			<< " monsters!"
			<< std::endl;	
		
		return context->view_manager->push(new CombatView(context, monsters));
	}
	return true;
}

const bool RoomView::inventory()
{
	return context->view_manager->push(new InventoryView(context));
}

const bool RoomView::dungeon()
{
	return context->view_manager->push(new MapView(context));
}

const bool RoomView::character()
{
	return context->view_manager->push(new CharacterView(context));
}

const bool RoomView::exit()
{
	return context->view_manager->push(new ExitView(context));
}

const bool RoomView::go()
{
	if (room->type == Room::DOWN) {
		context->gamestate->current_depth++;
		room = context->gamestate->get_dungeon()->find(Room::UP);
		room->visited = true;
		return true;
	}
	else if (room->type == Room::UP) {
		context->gamestate->current_depth--;
		room = context->gamestate->get_dungeon()->find(Room::DOWN);
		room->visited = true;
		return true;
	}
	else {
		return false;
	}
}

RoomView::~RoomView() {
	delete monsters;
}

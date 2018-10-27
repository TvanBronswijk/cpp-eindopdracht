#include "roomview.h"
#include "gamecontext.h"

RoomView::RoomView(GameContext* context, Room* room) : View(context)
{
	generator.seed(time(0));
	this->room = room;
}

std::ostream& RoomView::display()
{
	return std::cout
		<< this->room->to_string()
		<< std::endl
		<< "What do you want to do?"
		<< std::endl
		<< "[F]ight | [M]ove | [S]earch | [R]est | [I]nventory | [D]ungeon | [C]haracter | [E]xit"
		<< std::endl;
}

bool RoomView::handle_input()
{
	char a;
	std::cin >> a;

	switch (tolower(a)) {
	case 'f':
		fight();
		return true;
	case 'm':
		move();
		return true;
	case 's':
		search();
		return true;
	case 'r':
		rest();
		return true;
	case 'i':
		inventory();
		return true;
	case 'd':
		dungeon();
		return true;
	case 'c':
		character();
		return true;
	case 'e':
		exit();
		return true;
	}
	return false;
}

void RoomView::fight()
{
	context->view_manager->push(new CombatView(context, room->monsters));
}

void RoomView::move()
{
	std::cout
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
		this->room = target;
		target->visited = true;
	}
	else {
		std::cout << "That's not a valid direction" << std::endl;
	}
}

void RoomView::search()
{
	std::cout 
		<< "Do you want to pick it up?" 
		<< std::endl
		<< "[Y]es/[N]o"
		<< std::endl;

	char a;
	std::cin >> a;

	switch (tolower(a)) {
	case 'y':
		//TODO: pick up Item on the ground
		break;
	case 'n':
	default:
		break;
	}
}

void RoomView::rest()
{
	std::cout 
		<< "resting..." 
		<< std::endl;

	std::uniform_int_distribution<int> d(0, 10);
	if (d(generator) == 0) {
		int monster_count = d(generator);
		for (int i = room->monsters->size(); i < monster_count; i++)
			room->monsters->push(context->monster_generator->generate(1, 3));
		
		std::cout
			<< "You were ambushed by "
			<< room->monsters->size()
			<< " monsters!"
			<< std::endl;	
		
		fight();
	}

}

void RoomView::inventory()
{
	context->view_manager->push(new InventoryView(context));
}

void RoomView::dungeon()
{
	context->view_manager->push(new MapView(context));
}

void RoomView::character()
{
	context->view_manager->push(new CharacterView(context));
}

void RoomView::exit()
{
	context->gamestate->clear();
	back();
}

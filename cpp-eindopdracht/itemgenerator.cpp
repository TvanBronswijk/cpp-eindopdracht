#include "itemgenerator.h"

ItemGenerator::ItemGenerator() {
	items.push("Shortsword");
	items.push("Hammer");
	items.push("Speer");
	items.push("Dagger");
	items.push("Mace");
	items.push("Axe");
	items.push("Bow");
	items.push("crossbow");
	items.push("Katana");
	items.push("Longsword");
}

int ItemGenerator::Rand(size_t min, size_t max)
{
	std::uniform_int_distribution<int> d(min, max);
	return d(generator);
}

Item* ItemGenerator::create_item() {
	if(Rand(0, 1) == 1){
		return new Consumable("Potion", 20);
	}
	else
		return new Weapon(items.get(Rand(0, 9)), Rand(0, 10));
}

ItemGenerator::~ItemGenerator() {

}
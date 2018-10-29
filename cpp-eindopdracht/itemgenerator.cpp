#include "itemgenerator.h"

ItemGenerator::ItemGenerator(Random* random) {
	this->random = random;
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

Item* ItemGenerator::create_item() {
	if(random->get(1) == 1){
		return new Consumable("Potion", 20);
	}
	else
		return new Weapon(items.get(random->get(9)), random->get(1,10));
}

ItemGenerator::~ItemGenerator() {

}
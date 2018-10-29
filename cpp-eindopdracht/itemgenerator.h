#pragma once
#include <iostream>
#include "random.h"
#include "item.h"
#include "consumable.h"
#include "weapon.h"
#include "array.h"

class ItemGenerator {

private:
	Random* random;

	Array<const char*, 10> items;
public:
	ItemGenerator(Random* random);
	~ItemGenerator();
	Item* create_item();
};
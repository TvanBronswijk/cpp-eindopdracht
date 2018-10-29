#pragma once
#include <iostream>
#include "random.h"
#include "stringutil.h"
#include "filereader.h"
#include "monster.h"

class MonsterGenerator{
private:
	Random* random;

	int monster_count;
	Monster** templates;
public:
	MonsterGenerator(Random* random);
	~MonsterGenerator();

	void init();
	Monster* generate(int min_level, int max_level);
	Monster* clone(Monster* m);
};
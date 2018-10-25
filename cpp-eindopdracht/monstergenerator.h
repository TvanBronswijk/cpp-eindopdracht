#pragma once
#include <iostream>
#include <random>
#include "stringutil.h"
#include "filereader.h"
#include "monster.h"

class MonsterGenerator{
private:
	std::default_random_engine generator;

	int monster_count;
	Monster** templates;
	FileReader* fr;
public:
	MonsterGenerator(std::default_random_engine generator);
	~MonsterGenerator();

	void init();
	Monster* generate(int min_level, int max_level);
	Monster* clone(Monster* m);
};
#pragma once
#include <iostream>
#include <random>
#include <ctime>
#include "stringutil.h"
#include "filereader.h"
#include "monster.h"

class MonsterGenerator{
private:
	std::default_random_engine generator;

	int monster_count;
	Monster** templates;
public:
	MonsterGenerator();
	~MonsterGenerator();

	void init();
	Monster* generate(int min_level, int max_level);
	Monster* clone(Monster* m);
};
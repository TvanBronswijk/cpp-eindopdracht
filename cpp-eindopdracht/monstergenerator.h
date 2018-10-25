#pragma once
#include <iostream>
#include "stringutil.h"
#include "filereader.h"
#include "monster.h"

class MonsterGenerator{
private:
	int monster_count;
	Monster** templates;
	FileReader* fr;
public:
	MonsterGenerator();
	~MonsterGenerator();

	void init();
	Monster* generate();
};
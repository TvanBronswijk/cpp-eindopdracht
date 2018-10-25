#include "monstergenerator.h"

MonsterGenerator::MonsterGenerator()
{
	fr = new FileReader();
}

MonsterGenerator::~MonsterGenerator()
{
	delete fr;
	for (int i = 0; i < monster_count; i++)
		delete templates[i];
	delete[] templates;
}

void MonsterGenerator::init()
{
	monster_count = fr->count("monsters.txt");
	char** lines = fr->read("monsters.txt", monster_count);

	templates = new Monster*[monster_count];
	for (int i = 0; i < monster_count; i++)
	{
		Monster* m = new Monster();
		char** clms = StringUtil::split(lines[i], "[;]");
		
		m->name = new char[255];
		strcpy_s(m->name, 255, clms[0]);

		m->level = atoi(clms[1]);

		char** hit = StringUtil::split(clms[2], "x");
		m->hitchance = atoi(hit[0]);
		m->hitcount = atoi(hit[1]);
		delete hit[0];
		delete hit[1];
		delete[] hit;

		auto damage = StringUtil::split(clms[3], "-");
		m->min_damage = atoi(damage[0]);
		m->max_damage = atoi(damage[1]);
		delete damage[0];
		delete damage[1];
		delete[] damage;

		m->defense = atoi(clms[4]);

		m->hp = atoi(clms[5]);

		for (int i = 0; i < 6; i++)
			delete clms[i];
		delete[] clms;

		templates[i] = m;
		delete lines[i];
	}
	delete[] lines;

	for (int i = 0; i < monster_count; i++)
	{
		std::cout << templates[i]->name << std::endl;
	}
}

Monster* MonsterGenerator::generate()
{
	return nullptr;
}

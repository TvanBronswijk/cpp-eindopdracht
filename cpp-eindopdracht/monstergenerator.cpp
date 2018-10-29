#include "monstergenerator.h"

MonsterGenerator::MonsterGenerator(Random* random)
{
	this->random = random;
}

MonsterGenerator::~MonsterGenerator()
{
	for (int i = 0; i < monster_count; i++)
		delete templates[i];
	delete[] templates;
}

void MonsterGenerator::init()
{
	FileReader fr;
	monster_count = fr.count("monsters.txt");
	char** lines = fr.read("monsters.txt", monster_count);

	templates = new Monster*[monster_count];
	for (int i = 0; i < monster_count; i++)
	{
		Monster* m = new Monster();
		char** clms = StringUtil::split(lines[i], "[;]");
		
		m->name = new char[64];
		strcpy_s(m->name, 64, clms[0]);

		if (strcmp(clms[1], "BAAS") == 0)
			m->level = 99;
		else
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
}

Monster* MonsterGenerator::generate(int min_level, int max_level)
{
	Monster* tmpl = nullptr;
	while (tmpl == nullptr)
	{
		Monster* m = templates[random->get(monster_count-1)];
		if (m->level >= min_level && m->level <= max_level)
			tmpl = m;

	}
	return clone(tmpl);
}

Monster* MonsterGenerator::clone(Monster* m)
{
	Monster* result = new Monster();

	result->name = new char[64];
	strcpy_s(result->name, 64, m->name);

	result->level = m->level;
	result->hitchance = m->hitchance;
	result->hitcount = m->hitcount;
	result->min_damage = m->min_damage;
	result->max_damage = m->max_damage;
	result->defense = m->defense;
	result->hp = m->hp;

	return result;
}



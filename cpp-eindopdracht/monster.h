#pragma once

struct Monster {
	char* name;
	
	int level;

	int hitchance;
	int hitcount;

	int min_damage;
	int max_damage;

	int defense;

	int hp;

	~Monster() 
	{
		delete[] name;
	}
};
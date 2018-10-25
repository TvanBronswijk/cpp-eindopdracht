#pragma once
#include <random>
#include "monstergenerator.h"
#include "gamecontext.h"
#include "mainview.h"

class GameManager
{
private:
	GameContext* context;
	MonsterGenerator* monster_generator;
public:
	GameManager(std::default_random_engine generator);
	void init();
	~GameManager();
};

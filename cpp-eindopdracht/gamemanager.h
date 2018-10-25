#pragma once
#include <random>
#include "monstergenerator.h"
#include "roombuilder.h"
#include "gamecontext.h"
#include "mainview.h"

class GameManager
{
private:
	GameContext* context;
	MonsterGenerator* monster_generator;
	RoomBuilder* room_builder;
public:
	GameManager(std::default_random_engine generator);
	void init();
	~GameManager();
};

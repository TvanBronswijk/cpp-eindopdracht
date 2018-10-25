#pragma once
#include <random>
#include <ctime>
#include "gamecontext.h"
#include "mainview.h"

class GameManager
{
private:
	GameContext* context;
public:
	GameManager();
	void init();
	void run();
	~GameManager();
};

#pragma once
#include "random.h"
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

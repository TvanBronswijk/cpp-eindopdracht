#pragma once
#include "gamecontext.h"
#include "mainview.h"

class GameManager
{
private:
	GameContext* context;
public:
	GameManager();
	void init();
	~GameManager();
};

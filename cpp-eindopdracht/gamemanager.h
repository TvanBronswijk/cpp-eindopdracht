#pragma once
#include "viewmanager.h"
#include "statemanager.h"

#include "mainview.h"

class GameManager 
{
private:
	ViewManager view_manager;
	StateManager state_manager;
public:
	void init();
};

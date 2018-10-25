#pragma once
#include <iostream>

class GameContext;
class View
{
protected:
	GameContext* context;
public:
	View(GameContext* context);
	virtual void display() = 0;
	virtual void handle_input() = 0;
};
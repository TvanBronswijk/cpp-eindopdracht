#pragma once
#include <iostream>

class GameContext;
class View
{
protected:
	GameContext* context;
public:
	View(GameContext* context);
	virtual std::ostream& display() = 0;
	virtual bool handle_input() = 0;
};
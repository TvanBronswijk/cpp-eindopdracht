#pragma once
#include "view.h"
#include "player.h"

class MainView : public View
{
private:
	GameContext* context;
public:
	MainView(GameContext* context);
	void display() override;
	void handle_input() override;
};
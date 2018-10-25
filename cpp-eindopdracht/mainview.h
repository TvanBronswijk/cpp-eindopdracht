#pragma once
#include "view.h"

class MainView : public View
{
private:

public:
	MainView(GameContext* context);
	void display() override;
	void handle_input() override;
};
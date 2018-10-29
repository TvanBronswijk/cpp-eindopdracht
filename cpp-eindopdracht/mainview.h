#pragma once
#include "view.h"
#include "creditsview.h"
#include "roomview.h"
#include "charactercreationview.h"

class MainView : public View
{
private:
	bool handle_input(char c) override;
	bool yes();
	bool no();
	bool credits();
public:
	MainView(GameContext* context);
	std::ostream& display() override;
};
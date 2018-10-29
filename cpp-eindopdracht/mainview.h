#pragma once
#include "view.h"
#include "creditsview.h"
#include "dungeoncreationview.h"
#include "charactercreationview.h"

class MainView : public View
{
private:
	bool handle_input(char c) override;
	const bool yes();
	const bool no();
	const bool credits();
public:
	MainView(GameContext* context);
	std::ostream& display() override;
};
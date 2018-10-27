#pragma once
#include "view.h"
#include "creditsview.h"
#include "roomview.h"
#include "charactercreationview.h"

class MainView : public View
{
private:
	bool yes();
	bool no();
	bool credits();
public:
	MainView(GameContext* context);
	std::ostream& display() override;
	bool handle_input() override;
};
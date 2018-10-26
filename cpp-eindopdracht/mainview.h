#pragma once
#include "view.h"
#include "creditsview.h"
#include "roomview.h"
#include "charactercreationview.h"

class MainView : public View
{
private:
	void yes();
	void no();
	void credits();
public:
	MainView(GameContext* context);
	std::ostream& display() override;
	bool handle_input() override;
};
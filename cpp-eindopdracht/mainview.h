#pragma once
#include "player.h"
#include "view.h"
#include "roomview.h"

class MainView : public View
{
private:
	void yes();
	void no();
public:
	MainView(GameContext* context);
	std::ostream& display() override;
	bool handle_input() override;
};
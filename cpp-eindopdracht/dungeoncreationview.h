#pragma once
#include "view.h"
#include "gamecontext.h"
#include "Player.h"

class DungeonCreationView : public View
{
private:
	virtual bool handle_input(char c) override;
public:
	DungeonCreationView(GameContext* context);
	std::ostream& display() override;
	bool handle_input() override;
};
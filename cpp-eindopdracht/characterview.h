#pragma once
#include "player.h"
#include "view.h"

class CharacterView : public View
{
private:
	bool handle_input(char c) override;
	bool stats();
public:
	CharacterView(GameContext* context);
	std::ostream& display() override;
};
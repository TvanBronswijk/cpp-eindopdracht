#pragma once
#include "player.h"
#include "view.h"

class CharacterView : public View
{
private:
	bool stats();
	bool handle_input(char c) override;
public:
	CharacterView(GameContext* context);
	std::ostream& display() override;
};
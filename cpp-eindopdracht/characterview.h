#pragma once
#include "player.h"
#include "view.h"

class CharacterView : public View
{
private:
	void stats();
public:
	CharacterView(GameContext* context);
	std::ostream& display() override;
	bool handle_input() override;
};
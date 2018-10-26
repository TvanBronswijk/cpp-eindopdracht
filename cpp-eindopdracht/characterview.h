#pragma once
#include "player.h"
#include "view.h"

class CharacterView : public View
{
private:
	Player* player;
public:
	CharacterView(GameContext* context, Player* player);
	std::ostream& display() override;
	bool handle_input() override;
};
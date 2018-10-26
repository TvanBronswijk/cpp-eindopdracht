#pragma once
#include "view.h"
#include "gamecontext.h"
#include "Player.h"

class CharacterCreationView : public View
{
public:
	CharacterCreationView(GameContext* context);
	std::ostream& display() override;
	bool handle_input() override;
};
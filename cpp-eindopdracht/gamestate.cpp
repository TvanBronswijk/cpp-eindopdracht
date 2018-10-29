#include "gamestate.h"

GameState::GameState()
{

}

GameState::~GameState()
{
	delete dungeon;
	delete player;
}
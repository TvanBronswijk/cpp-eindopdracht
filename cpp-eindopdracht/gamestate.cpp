#include "gamestate.h"

GameState::GameState()
{

}

GameState::~GameState()
{
	delete config;
	delete dungeon;
	delete player;
}
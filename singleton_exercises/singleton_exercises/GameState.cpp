#include "GameState.h"

GameState::GameState() {}

void GameState::operator=(GameState const &) {}

GStates GameState::getState()
{
	return cStates;
}

void GameState::setState(GStates newState)
{
	cStates = newState;
}

GameState & GameState::GetInstance()
{
	static GameState instance;
	return instance;
}

GameState::~GameState()
{
}

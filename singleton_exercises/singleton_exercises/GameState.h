#pragma once

enum GStates
{
	MainMenu,
	PlayerSelect,
	InGame,
	GameOver
};

class GameState
{
	GStates cStates = MainMenu;
	GameState();
	GameState(GameState const&);
	void operator=(GameState const&);
public:
	GStates getState();
	void setState(GStates newState);
	static GameState& GetInstance();
	~GameState();
};


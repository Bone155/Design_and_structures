#include <iostream>
#include "GameState.h"
#include <string>

using std::cout;
using std::cin;
using std::endl;

int main() {
	int state = 0;
	cout << "Enter the state your in" << endl;
	std::string input;
	cin >> input;
	if (input == "mainmenu")
		state = 0;
	else if (input == "playerselect")
		state = 1;
	else if (input == "ingame")
		state = 2;
	else if (input == "gameover")
		state = 3;
	switch (state)
	{
		case 0:
			GameState::GetInstance().setState(MainMenu);
			input = "In MainMenu";
			break;
		case 1:
			GameState::GetInstance().setState(PlayerSelect);
			input = "choosing a sprite";
			break;
		case 2:
			GameState::GetInstance().setState(InGame);
			input = "In game";
			break;
		case 3:
			GameState::GetInstance().setState(GameOver);
			input = "Game Over";
			break;
		default:
			break;
	}

	cout << input << endl;
	system("pause");
	return 0;
}
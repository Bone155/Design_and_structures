#include "Player.h"

Player::Player(const string & filename)
{
	mySprite = LoadTexture(filename.c_str());
}

Player::~Player()
{
	UnloadTexture(mySprite);
}

bool Player::moveTo(const Vector2 & dest)
{
	if (position.x == dest.x && position.y == dest.y)
		return true;
	else
		return false;
}

void Player::draw()
{
	DrawTexture(mySprite, GetScreenWidth() / 2, GetScreenHeight() / 2, RED);
}

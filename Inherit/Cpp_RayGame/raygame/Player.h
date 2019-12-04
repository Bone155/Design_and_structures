#pragma once
#include "raylib.h"
#include <iostream>

using std::string;

class Player
{
public:
	Player(const string &filename);
	~Player();

	Vector2 position;
	float speed = 0;
	Texture2D mySprite;
	bool select;
	bool moveTo(const Vector2 &dest);

	void draw();
};


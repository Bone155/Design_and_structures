#pragma once

#include "raylib.h"
#include <iostream>
#include <string>

using std::string;

class Sprite : public Vector2
{
public:
	Texture2D* spriteCells = nullptr;
	float frameRate = 25.0;
	int frameCount = 0;
	int direction = 1;

	void Draw();
	
	Sprite();
	Sprite(const string* filename, const int cellCount, const float fr);
	~Sprite();
};


#pragma once
#include "Sprite.h"
class Button : public Sprite
{
	Vector2 position;
public:
	void Draw();
	bool CheckForClick();

	Button(const string* filename, const Vector2 &position, const int cellCount);
	Button();
	~Button();
};


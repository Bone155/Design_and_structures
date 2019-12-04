#pragma once
#include "Sprite.h"
class Button : public Sprite
{
	Vector2 position;
public:
	Color c;
	void Draw();
	bool CheckForClick();

	Button(const string* filename, const Vector2 &position, const int cellCount, Color _c);
	Button();
	~Button();
};


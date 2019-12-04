#include "Button.h"

void Button::Draw()
{
	static int fidx = 0;
	static float timer = 0;
	timer += GetFrameTime();
	
	DrawTexture(spriteCells[fidx], position.x, position.y, c);
	Rectangle rec = { (float)position.x, (float)position.y, (float)spriteCells[fidx].width, (float)spriteCells[fidx].height};
	
	DrawRectangleLinesEx(rec, 3,  BLACK);
	if (timer > 1 / frameRate) {

		fidx++;
		if (fidx >= frameCount)
			fidx = 0;
		timer = 0;
	}
}

bool Button::CheckForClick()
{
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		return true;
	else
		return false;
}

Button::Button(const string * filename, const Vector2 & pos, const int cellCount, Color _c)
{
	spriteCells = new Texture[cellCount];
	for (int i = 0; i < cellCount; i++) {
		spriteCells[i] = LoadTexture(filename[i].c_str());
	}
	frameCount = cellCount;
	position = pos;
	c = _c;
}

Button::Button()
{
}


Button::~Button()
{
}

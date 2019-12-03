#include "Sprite.h"

void Sprite::Draw()
{
	static int fidx = 0;
	static float timer = 0;
	timer += GetFrameTime();
	
	DrawTexture(spriteCells[fidx], 300, 225, GREEN);
	if (timer > 1 / frameRate) {

		fidx++;
		if (fidx >= frameCount)
			fidx = 0;
		timer = 0;
	}
}

Sprite::Sprite()
{
}

Sprite::Sprite(const string * filename, const int cellCount, const float fr)
{
	spriteCells = new Texture[cellCount];
	for (int i = 0; i < cellCount; i++) {
		spriteCells[i] = LoadTexture(filename[i].c_str());
	}
	frameCount = cellCount;
	frameRate = fr;
}


Sprite::~Sprite()
{
}

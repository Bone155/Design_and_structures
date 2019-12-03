/*******************************************************************************************
*
*   raylib [core] example - basic window
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2013-2016 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include "Sprite.h"
#include "Button.h"

int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 800;
	int screenHeight = 450;
	
	InitWindow(screenWidth, screenHeight, "Inheritance project");

	string walkPics[]{
		"PNG\\Player\\Poses\\player_walk1.png",
		"PNG\\Player\\Poses\\player_walk2.png"
	};

	Sprite walk = {walkPics, 2, 8};

	Vector2 pos = { 400, 50 };
	string buttonPic[]{ "PNG\\blue_button07.png" };
	Button button = { buttonPic, pos, 1 };

	SetTargetFPS(60);
	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		// TODO: Update your variables here
		//----------------------------------------------------------------------------------

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(RAYWHITE);

		/*if (IsKeyDown(KEY_A))
			player.x -= 5;
		if (IsKeyDown(KEY_D))
			player.x += 5;
		if (IsKeyDown(KEY_W))
			player.y += 5;
		if (IsKeyDown(KEY_S))
			player.y -= 5;*/

		walk.Draw();

		button.Draw();

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}
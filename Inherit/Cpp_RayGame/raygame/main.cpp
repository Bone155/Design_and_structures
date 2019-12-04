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
#include "Player.h"

int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 800;
	int screenHeight = 450;
	
	InitWindow(screenWidth, screenHeight, "Inheritance project");

	Vector2 wizButtonPos = { 10, 10 };
	string wizButtonPic[]{ "PNG\\blue_button04.png" };
	Button wizButton = { wizButtonPic, wizButtonPos, 1, SKYBLUE };

	Vector2 barButtonPos = { screenWidth - 200, 10 };
	string barButtonPic[]{ "PNG\\red_button01.png" };
	Button barButton = { barButtonPic, barButtonPos, 1, ORANGE };

	string wiz = "Wizard";
	string bar = "Barbarian";
	Vector2 wizText = { wizButtonPos.x, wizButtonPos.y };
	Vector2 barText = { barButtonPos.x, barButtonPos.y };

	Player wizard = { "PNG\\blue_button10.png" };
	Player barbarian = { "PNG\\red_button09.png" };

	SetTargetFPS(60);
	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		// TODO: Update your variables here
		//----------------------------------------------------------------------------------

		if (CheckCollisionPointRec(GetMousePosition(), barButton.rec))
		{
			barButton.c = WHITE;
			if(barButton.CheckForClick())
				barbarian.select = true;
		}
		else {
			barbarian.select = false;
		}

		if (CheckCollisionPointRec(GetMousePosition(), wizButton.rec))
		{
			wizButton.c = WHITE;
			if(wizButton.CheckForClick())
				wizard.select = true;
		}
		else {
			wizard.select = false;
		}

		while (wizard.select == true) {

			if (wizButton.CheckForClick()) {
				wizard.position.x = GetMousePosition().x; wizard.position.y = GetMousePosition().y;
			}
		}

		while (barbarian.select == true) {

			if (barButton.CheckForClick()) {
				barbarian.position.x = GetMousePosition().x; barbarian.position.y = GetMousePosition().y;
			}
		}

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

		wizButton.Draw();
		barButton.Draw();

		wizard.draw();
		barbarian.draw();

		DrawText(wiz.c_str(), wizText.x + 40, wizText.y + 12, 25, DARKBLUE);
		DrawText(bar.c_str(), barText.x + 40, barText.y + 12, 25, MAROON);

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}
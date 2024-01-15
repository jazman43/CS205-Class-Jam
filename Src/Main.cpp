/*

CS205 - jam -- Platformer

Raylib

*/

#include "raylib.h"
#include "CharacterController.h"
#include "Envioment.h"



int main()
{
	const int windowWidth = 1200;
	const int windowHeight = 800;

	InitWindow(windowWidth, windowHeight, "Jam- Plaformer");


	SetTargetFPS(60);

	CharacterController controller;
	Envioment envioment;

	while (!WindowShouldClose())
	{
		//update var
		controller.CharacterMovement(Vector3{0,0,0}, Vector3{32.0f, 0.0f, 32.0f});
		
		if (IsKeyPressed(KEY_Q))
		{
			DisableCursor();
		}
		else if(IsKeyPressed(KEY_P))
		{
			EnableCursor();
		}
		//Draw
		BeginDrawing();

		ClearBackground(RAYWHITE);
		
		DrawFPS(15, 15);

		BeginMode3D(controller.GetPlayerCam());

		
		envioment.DrawGround();

		EndMode3D();

		EndDrawing();
	}

	CloseWindow();

	return 0;
}
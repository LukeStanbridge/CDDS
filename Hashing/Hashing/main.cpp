#include <iostream>
#include "raylib.h"
#include "HashFunction.h"

int main()
{
	int screenWidth = 1600;
	int screenHeight = 800;

	InitWindow(screenWidth, screenHeight, "Hashbrowns");
	SetTargetFPS(60);
	Image image1 = LoadImage("hashbrown.png"); 
	ImageResize(&image1, 100, 100);
	Texture2D hashbrown = LoadTextureFromImage(image1);
	Image image2 = LoadImage("weedbrownies.png");
	ImageResize(&image2, 100, 100);
	Texture2D hashbrownie = LoadTextureFromImage(image2);

	while (!WindowShouldClose())
	{
		// Update
		//----------------------------------------------------------------------------------
		HashTable hashy;

		hashy.insert("good", hashbrown);
		hashy.insert("bad", hashbrownie);

		//----------------------------------------------------------------------------------

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();
			ClearBackground(RAYWHITE);

			DrawText("Hashy Textures", 670, 30, 20, RED);

			hashy.draw();
			hashy.print();

			hashy.get("bad");

			DrawFPS(10, 10);
		EndDrawing();
	}

	CloseWindow();
	return 0;
}
#include <iostream>
#include "raylib.h"
#include "Hashing.h"

int main()
{
	int screenWidth = 1600; 
	int screenHeight = 800;

	InitWindow(screenWidth, screenHeight, "Hashbrowns"); // create window in raylib
	SetTargetFPS(60);
	Image image1 = LoadImage("hashbrown.png"); // load images and resize to fit comfortably
	ImageResize(&image1, 100, 100);
	Texture2D hashbrown = LoadTextureFromImage(image1);
	Image image2 = LoadImage("weedbrownies.png");
	ImageResize(&image2, 100, 100);
	Texture2D hashbrownie = LoadTextureFromImage(image2);

	while (!WindowShouldClose())
	{
		//----------------------------------------------------------------------------------
		// Update
		//----------------------------------------------------------------------------------
		HashTable hashy; // create table

		hashy.insert("good", hashbrown); // insert key and image into table
		hashy.insert("bad", hashbrownie);

		//----------------------------------------------------------------------------------
		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing(); // draw window
			ClearBackground(RAYWHITE);

			DrawText("Hashy Textures", 670, 30, 20, RED);
			DrawText("Inserting images of good and bad hashy's into a hash table", 800, 250, 20, BLUE);

			hashy.draw(); // items in hash table
			hashy.print(); // print contents of each bucket

			hashy.get("bad");  // get function

			DrawFPS(10, 10);
		EndDrawing();
	}

	CloseWindow();
	return 0;
}
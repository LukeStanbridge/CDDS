#include "EntityDisplayApp.h"

EntityDisplayApp::EntityDisplayApp(int screenWidth, int screenHeight) : m_screenWidth(screenWidth), m_screenHeight(screenHeight) {

}

EntityDisplayApp::~EntityDisplayApp() {

}

bool EntityDisplayApp::Startup() {

	InitWindow(m_screenWidth, m_screenHeight, "EntityDisplayApp");
	SetTargetFPS(60);
	AccessFileMapping();
	AccessFileSize();

	return true;
}

void EntityDisplayApp::Shutdown() {

	CloseHandle(handle);
	CloseHandle(arraySize);
	CloseWindow();        // Close window and OpenGL context
}

void EntityDisplayApp::Update(float deltaTime) {


	Entity* data = (Entity*)MapViewOfFile(handle, FILE_MAP_ALL_ACCESS, 0, 0, sizeof(Entity));
	int* size = (int*)MapViewOfFile(arraySize, FILE_MAP_ALL_ACCESS, 0, 0, sizeof(int));
	if (data)
	{
		for (int i = 0; i < *size; i++)
		{
			m_entities.push_back(data[i]);
		}
	}

	UnmapViewOfFile(size);
	UnmapViewOfFile(data);
}

void EntityDisplayApp::Draw() {
	BeginDrawing();

	ClearBackground(RAYWHITE);

	// draw entities
	for (auto& entity : m_entities) {
		DrawRectanglePro(
			Rectangle{ entity.x, entity.y, entity.size, entity.size }, // rectangle
			Vector2{ entity.size / 2, entity.size / 2 }, // origin
			entity.rotation,
			Color{ entity.r, entity.g, entity.b, 255 });
	}
	m_entities.clear();
	// output some text, uses the last used colour
	DrawText("Press ESC to quit", 630, 15, 12, LIGHTGRAY);

	EndDrawing();
}
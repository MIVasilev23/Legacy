#include "main_menu.h"
#include "raylib.h"
#include <iostream>

void main_menu()
{
    InitWindow(845, 600, "TimeGrid");
    Texture2D background = LoadTexture("Assets/background_1.png");

    if (background.id == 0)
    {
        std::cout << "Failed to load background!" << std::endl;
        return;
    }

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_ESCAPE))
        {
            break;
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawTexture(background, 0, 0, WHITE);

        DrawText( "Press ESC to close the app", 10, 10, 20,BLACK);
        EndDrawing();
    }
    UnloadTexture(background);
}
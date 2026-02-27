#include "main_menu.h"
#include "raylib.h"
#include <iostream>

using namespace std;

void main_menu()
{
    InitWindow(800, 600, "Main Menu");

    Texture2D background = LoadTexture("Assets/test_background.png");

    if (background.id == 0)
    {
        cout << "Failed to load background!" << endl;
        CloseWindow();
        return;
    }

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawTexture(background, 0, 0, WHITE);

        EndDrawing();
    }

    UnloadTexture(background);
    CloseWindow();
}
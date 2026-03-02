#include "main_menu.h"
#include "buttons.h"
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

    Button viewButton("Assets/button_layout.png", 312, 200, 1.0f);
    Button createButton("Assets/button_layout.png", 312, 280, 1.0f);
    Button helpButton("Assets/button_layout.png", 312, 360, 1.0f);

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

        viewButton.Draw();
        createButton.Draw();
        helpButton.Draw();

        DrawText("VIEW EVENTS", 348, 300, 20, BLACK);
        DrawText("CREATE EVENT", 342, 380, 20, BLACK);
        DrawText("HOW TO USE?", 352, 460, 20, BLACK);

        EndDrawing();
    }

    UnloadTexture(background);
}
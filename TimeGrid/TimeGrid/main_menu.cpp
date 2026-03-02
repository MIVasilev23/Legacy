#include "main_menu.h"
#include "buttons.h"
#include "raylib.h"
#include <iostream>

enum class Screen
{
    main_menu,
    view_events,
    create_event,
    how_to_use,
    EXIT
};

void main_menu()
{
    InitWindow(845, 600, "TimeGrid");

    Texture2D background = LoadTexture("Assets/background_1.png");
    if (background.id == 0) std::cout << "Failed to load background!" << std::endl;

    Texture2D logo = LoadTexture("Assets/TimeGrid_logo1.png");
    if (logo.id == 0) std::cout << "Failed to load logo!" << std::endl;

    Button viewButton("Assets/button_layout.png", 312, 280, 1.0f);
    Button createButton("Assets/button_layout.png", 312, 360, 1.0f);
    Button helpButton("Assets/button_layout.png", 312, 440, 1.0f);

    SetTargetFPS(60);
    Screen currentScreen = Screen::main_menu;

    while (!WindowShouldClose() && currentScreen != Screen::EXIT)
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        switch (currentScreen)
        {
        case Screen::main_menu:

            DrawTexture(background, 0, 0, WHITE);
            if (logo.id != 0)
            {
                float scale = 0.9f;
                DrawTextureEx(logo, { (840 - logo.width * scale) / 2, 32 }, 0.0f, scale, WHITE);
            }

            DrawText("Press ESC to close the app", 10, 10, 20, BLACK);

            viewButton.Draw();
            createButton.Draw();
            helpButton.Draw();

            DrawText("VIEW EVENTS", 348, 300, 20, BLACK);
            DrawText("CREATE EVENT", 342, 380, 20, BLACK);
            DrawText("HOW TO USE?", 352, 460, 20, BLACK);

            if (viewButton.IsPressed()) currentScreen = Screen::view_events;
            if (createButton.IsPressed()) currentScreen = Screen::create_event;
            if (helpButton.IsPressed()) currentScreen = Screen::how_to_use;

            if (IsKeyPressed(KEY_ESCAPE)) currentScreen = Screen::EXIT;
            break;

        case Screen::view_events:
            DrawText("VIEW EVENTS WORKS!", 150, 150, 30, RED);
            DrawText("Press F1 to return", 150, 200, 20, DARKGRAY);
            if (IsKeyPressed(KEY_F1)) currentScreen = Screen::main_menu;
            break;

        case Screen::create_event:
            DrawText("CREATE EVENT WORKS!", 150, 150, 30, BLUE);
            DrawText("Press F1 return", 150, 200, 20, DARKGRAY);
            if (IsKeyPressed(KEY_F1)) currentScreen = Screen::main_menu;
            break;

        case Screen::how_to_use:
            DrawText("HOW TO USE WORKS!", 150, 150, 30, GREEN);
            DrawText("Press F1 to return", 150, 200, 20, DARKGRAY);
            if (IsKeyPressed(KEY_F1)) currentScreen = Screen::main_menu;
            break;

        default:
            break;
        }

        EndDrawing();
    }

    UnloadTexture(background);
    if (logo.id != 0) UnloadTexture(logo);
    CloseWindow();
}
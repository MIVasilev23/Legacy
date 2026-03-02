#include "main_menu.h"
#include "buttons.h"
#include "view_events.h"
#include "raylib.h"
#include <iostream>

#include "event_list.h"


void main_menu()
{
    InitWindow(845, 600, "TimeGrid");

    Texture2D background = LoadTexture("Assets/background_1.png");

    if (background.id == 0)
    {
        std::cout << "Failed to load background!" << std::endl;
        return;
    }

    Texture2D logo = LoadTexture("Assets/TimeGrid_logo1.png");
    if (logo.id == 0)
    {
        std::cout << "Failed to load logo!" << std::endl;
        
    }

    Button viewButton("Assets/button_layout.png", 312, 200, 1.0f);
    Button createButton("Assets/button_layout.png", 312, 280, 1.0f);
    Button helpButton("Assets/button_layout.png", 312, 360, 1.0f);

    SetTargetFPS(60);

    //we need this to check if the button and linked lists work
    EventNode* head = nullptr;
    // Add a dummy event to test
    Event testEvent;
    testEvent.name = "Battle of Example";
    testEvent.year = 2023;

    AddEvent(head, testEvent);
    //delete or improve after it

    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_ESCAPE))
        {
            break;
        }

        //test window, delete or improve later
        if (viewButton.IsPressed())
        {
            view_events(head); 
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawTexture(background, 0, 0, WHITE);

        if (logo.id != 0) {
            float scale = 0.9f;
            DrawTextureEx(logo, { (840 - logo.width * scale) / 2, 32 }, 0.0f, scale, WHITE);
        }

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
    if (logo.id != 0)
        UnloadTexture(logo);
}
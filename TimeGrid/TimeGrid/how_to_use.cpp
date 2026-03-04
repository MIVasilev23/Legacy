#include "how_to_use.h"
#include "raylib.h"

void how_to_use()
{
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_F1))
            break;

        BeginDrawing(); 
        ClearBackground(RAYWHITE);

        DrawText("HOW TO USE", 300, 50, 30, BLACK);

        DrawText("1. Click CREATE EVENT to add a new event.", 120, 140, 20, DARKGRAY);
        DrawText("2. Fill in the fields using your keyboard.", 120, 180, 20, DARKGRAY);
        DrawText("3. Press TAB to switch between fields.", 120, 220, 20, DARKGRAY);
        DrawText("4. Press ENTER to save the event.", 120, 260, 20, DARKGRAY);
        DrawText("5. Click VIEW EVENTS to see all events.", 120, 300, 20, DARKGRAY);
        DrawText("6. Click an event to edit or delete it.", 120, 340, 20, DARKGRAY);

        DrawText("Press F1 to return to Main Menu.", 220, 420, 22, MAROON);

        EndDrawing();
    }
}
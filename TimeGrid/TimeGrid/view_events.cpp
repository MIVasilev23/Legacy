#include "raylib.h"

void view_events() //just for testing
{
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("works btw", 150, 150, 30, RED);
        DrawText("Press F1 to return", 150, 200, 20, DARKGRAY);

        EndDrawing();

        if (IsKeyPressed(KEY_F1))
            break;
    }
}
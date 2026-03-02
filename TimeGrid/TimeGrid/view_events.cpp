#include "view_events.h"
#include "raylib.h"

//delete this later Toshe, it's just a test if the program will run
void view_events(EventNode* head)
{
    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_ESCAPE))
            break;

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("VIEW EVENTS (ESC to return)", 20, 20, 20, BLACK);

        int y = 80;
        EventNode* current = head;

        while (current)
        {
            DrawText(
                current->data.name.c_str(),
                40,
                y,
                20,
                BLACK
            );

            DrawText(
                TextFormat("%d", current->data.year),
                300,
                y,
                20,
                DARKGRAY
            );

            y += 30;
            current = current->next;
        }

        EndDrawing();
    }
}
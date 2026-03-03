#include "view_events.h"
#include "raylib.h"

void view_events(EventNode* head)
{
    if(!head)return;

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_F1)) break;

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("VIEW EVENTS (F1 to return)", 20, 20, 20, BLACK);

        int y = 80; //starting Y position
        EventNode* current = head;

        while (current)
        {
            DrawText(current->data.name.c_str(), 40, y, 20, BLACK);
            DrawText(TextFormat("%d", current->data.year), 300, y, 20, DARKGRAY);

            y += 30; //thats for the spacing between events
            current = current->next;
        }

        EndDrawing();
    }
}
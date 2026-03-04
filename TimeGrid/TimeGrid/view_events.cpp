#include "view_events.h"
#include "edit_event.h"
#include "raylib.h"
#include <string>

void view_events(EventNode* head)
{
    Texture2D background = LoadTexture("Assets/background_1.png");
    SetTargetFPS(60);

    float scrollOffset = 0.0f;
    const float scrollSpeed = 30.0f;

    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_F1)) break;

        float wheel = GetMouseWheelMove();
        scrollOffset += wheel * scrollSpeed;

        if (scrollOffset > 0) scrollOffset = 0;

        BeginDrawing();
        DrawTexturePro(
            background,
            Rectangle{ 0, 0, (float)background.width, (float)background.height },
            Rectangle{ 0, 0, (float)GetScreenWidth(), (float)GetScreenHeight() },
            Vector2{ 0, 0 }, 0.0f, WHITE);

        DrawText("VIEW EVENTS", 20, 20, 30, BLACK);
        DrawText("F1 TO RETURN", 640, 20, 25, DARKGRAY);

        int y = 75 + (int)scrollOffset;
        EventNode* current = head;

        while (current)
        {
            //box for each event 
            Rectangle cardRect = { 20,(float)y, (float)GetScreenWidth() - 40, 125 };
            DrawRectangleRec(cardRect, LIGHTGRAY);
            DrawRectangleLinesEx(cardRect, 2, GRAY);

            if (CheckCollisionPointRec(GetMousePosition(), cardRect) &&
                IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                edit_event(head, current);
                break;// pass head and clicked event
            }

            //main Info
            DrawText(current->data.name.c_str(), cardRect.x + 15, cardRect.y + 12, 20, MAROON);
            DrawText(TextFormat("Year: %d", current->data.year), cardRect.x + 350, cardRect.y + 12, 18, BLACK);

            //theme & Leader
            DrawText(TextFormat("Theme: %s", current->data.theme.c_str()), cardRect.x + 15, cardRect.y + 45, 17, DARKBLUE);
            DrawText(TextFormat("Leader: %s", current->data.leader.c_str()), cardRect.x + 350, cardRect.y + 45, 17, DARKGREEN);

            //participants 
            std::string partText = "Participants: " + current->data.participants;
            if (partText.length() > 45) {
                std::string line1 = partText.substr(0, 42) + "...";
                DrawText(line1.c_str(), cardRect.x + 15, cardRect.y + 75, 17, DARKPURPLE);
                DrawText("(Check details for more)", cardRect.x + 15, cardRect.y + 95, 15, GRAY);
            }
            else {
                DrawText(partText.c_str(), cardRect.x + 15, cardRect.y + 75, 17, DARKPURPLE);
            }

            Rectangle resRect = { cardRect.x + cardRect.width - 180, cardRect.y + 10, 170, 105 };
            DrawRectangleRec(resRect, Fade(GOLD, 0.1f));
            DrawText("RESULT:", resRect.x + 10, resRect.y + 15, 15, DARKGRAY);

            std::string resVal = current->data.result;
            if (resVal.length() > 14) resVal = resVal.substr(0, 12) + "...";
            DrawText(resVal.c_str(), resRect.x + 10, resRect.y + 45, 18, RED);

            y += 140; //spacing for the next box
            current = current->next;

        }

        if (!head) DrawText("No events found.", 40, 100, 20, GRAY);

        EndDrawing();
    }
    UnloadTexture(background);
}







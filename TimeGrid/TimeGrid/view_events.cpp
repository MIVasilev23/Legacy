#include "view_events.h"
#include "raylib.h"
#include <string>

void view_events(EventNode* head)
{
    Texture2D background = LoadTexture("Assets/background_1.png");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_F1)) break;

        BeginDrawing();
        DrawTexturePro(
            background,
            Rectangle{ 0, 0, (float)background.width, (float)background.height },
            Rectangle{ 0, 0, (float)GetScreenWidth(), (float)GetScreenHeight() },
            Vector2{ 0, 0 },
            0.0f,
            WHITE
        );

        DrawText("VIEW EVENTS (F1 to return)", 20, 20, 25, DARKGRAY);

        int y = 75;
        EventNode* current = head;

        while (current)
        {
            // 1. Box for each event 
            Rectangle cardRect = { 20, (float)y, (float)GetScreenWidth() - 40, 125 };
            DrawRectangleRec(cardRect, LIGHTGRAY);
            DrawRectangleLinesEx(cardRect, 2, GRAY);

            // Main Info
            DrawText(current->data.name.c_str(), cardRect.x + 15, cardRect.y + 12, 20, MAROON);
            DrawText(TextFormat("Year: %d", current->data.year), cardRect.x + 350, cardRect.y + 12, 18, BLACK);

            // Theme & Leader
            DrawText(TextFormat("Theme: %s", current->data.theme.c_str()), cardRect.x + 15, cardRect.y + 45, 17, DARKBLUE);
            DrawText(TextFormat("Leader: %s", current->data.leader.c_str()), cardRect.x + 350, cardRect.y + 45, 17, DARKGREEN);

            // Participants 
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

            y += 140; // Spacing for the next box
            current = current->next;

            if (y > GetScreenHeight() - 40) break;
        }

        if (!head) DrawText("No events found.", 40, 100, 20, GRAY);

        EndDrawing();
    }
    UnloadTexture(background);
}







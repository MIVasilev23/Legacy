#include "create_event.h"
#include "file_manager.h"
#include "raylib.h"
#include <string>

#include "event_list.h"

void create_event(EventNode*& head)
{
    std::string name = "";
    std::string yearInput = "";
    std::string theme = "";
    std::string leader = "";
    std::string participants = "";
    std::string result = "";

    int currentField = 0;

    SetTargetFPS(60);
    Texture2D background = LoadTexture("Assets/background_1.png");

    while (!WindowShouldClose())
    {
        //character input
        int key = GetCharPressed();
        while (key > 0)
        {
            char c = (char)key;
            switch (currentField)
            {
            case 0: name += c; break;
            case 1: yearInput += c; break;
            case 2: theme += c; break;
            case 3: leader += c; break;
            case 4: participants += c; break;
            case 5: result += c; break;
            }
            key = GetCharPressed();
        }

        if (IsKeyPressed(KEY_BACKSPACE))
        {
            switch (currentField)
            {
            case 0: if (!name.empty()) name.pop_back(); break;
            case 1: if (!yearInput.empty()) yearInput.pop_back(); break;
            case 2: if (!theme.empty()) theme.pop_back(); break;
            case 3: if (!leader.empty()) leader.pop_back(); break;
            case 4: if (!participants.empty()) participants.pop_back(); break;
            case 5: if (!result.empty()) result.pop_back(); break;
            }
        }

        //switches between fields
        if (IsKeyPressed(KEY_TAB))
            currentField = (currentField + 1) % 6;

        //saves event with ENTER
        if (IsKeyPressed(KEY_ENTER) && !name.empty() && !yearInput.empty())
        {
            Event e;
            e.name = name;
            e.year = std::stoi(yearInput);
            e.theme = theme;
            e.leader = leader;
            e.participants = participants;
            e.result = result;

            AddEvent(head, e);       //add to linked list
            SaveEventToFile(e);

            name.clear(); yearInput.clear(); theme.clear();
            leader.clear(); participants.clear(); result.clear();
            currentField = 0;
        }

        if (IsKeyPressed(KEY_F1))
            break;

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawTexture(background, 0, 0, WHITE);

        DrawText("CREATE EVENT", 300, 40, 30, BLACK);
        DrawText("TAB to switch fields, ENTER to save, F1 to return", 160, 80, 20, DARKGRAY);

        //Name
        DrawText("Event Name:", 200, 140, 20, BLACK);
        DrawRectangleLines(200, 160, 400, 40, currentField == 0 ? RED : GRAY);
        DrawText(name.c_str(), 210, 180, 20, BLACK);

        //Year
        DrawText("Year:", 200, 220, 20, BLACK);
        DrawRectangleLines(200, 240, 400, 40, currentField == 1 ? RED : GRAY);
        DrawText(yearInput.c_str(), 210, 260, 20, BLACK);

        //Theme
        DrawText("Theme:", 200, 290, 20, BLACK);
        DrawRectangleLines(200, 310, 400, 40, currentField == 2 ? RED : GRAY);
        DrawText(theme.c_str(), 210, 330, 20, BLACK);

        //Leader
        DrawText("Leader:", 200, 360, 20, BLACK);
        DrawRectangleLines(200, 380, 400, 40, currentField == 3 ? RED : GRAY);
        DrawText(leader.c_str(), 210, 400, 20, BLACK);

        //Participants
        DrawText("Participants:", 200, 430, 20, BLACK);
        DrawRectangleLines(200, 450, 400, 40, currentField == 4 ? RED : GRAY);
        DrawText(participants.c_str(), 210, 470, 20, BLACK);

        //Result
        DrawText("Result:", 200, 500, 20, BLACK);
        DrawRectangleLines(200, 520, 400, 40, currentField == 5 ? RED : GRAY);
        DrawText(result.c_str(), 210, 540, 20, BLACK);

        EndDrawing();
    }
    UnloadTexture(background);

}

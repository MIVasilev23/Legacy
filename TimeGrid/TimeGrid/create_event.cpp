#include "create_event.h"
#include "file_manager.h"
#include "raylib.h"
#include <string>
#include "event_list.h"

void create_event(EventNode*& head)
{
    // Input storage
    std::string name = "";
    std::string yearInput = "";
    std::string theme = "";
    std::string leader = "";
    std::string participants = "";
    std::string result = "";

    int currentField = 0; 

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        // Handle character input
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

        // Handle backspace
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

        // Switch field with TAB
        if (IsKeyPressed(KEY_TAB))
            currentField = (currentField + 1) % 6;

        // Save event with ENTER 
        if (IsKeyPressed(KEY_ENTER) && !name.empty() && !yearInput.empty())
        {
            Event e;
            e.name = name;
            e.year = std::stoi(yearInput);
            e.theme = theme;
            e.leader = leader;
            e.participants = participants;
            e.result = result;

            AddEvent(head, e);       // add to linked list
            SaveEventToFile(e);      // append to file

            // Reset inputs for next entry
            name.clear(); yearInput.clear(); theme.clear();
            leader.clear(); participants.clear(); result.clear();
            currentField = 0;
        }

        // Return to main menu 
        if (IsKeyPressed(KEY_F1))
            break;

        // Draw UI
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("CREATE EVENT", 300, 40, 30, BLACK);
        DrawText("TAB to switch field, ENTER to save, F1 to return", 120, 80, 20, DARKGRAY);

        // Name
        DrawText("Event Name:", 200, 140, 20, BLACK);
        DrawRectangleLines(200, 170, 400, 40, currentField == 0 ? RED : GRAY);
        DrawText(name.c_str(), 210, 180, 20, BLACK);

        // Year
        DrawText("Year:", 200, 220, 20, BLACK);
        DrawRectangleLines(200, 250, 400, 40, currentField == 1 ? RED : GRAY);
        DrawText(yearInput.c_str(), 210, 260, 20, BLACK);

        // Theme
        DrawText("Theme:", 200, 290, 20, BLACK);
        DrawRectangleLines(200, 320, 400, 40, currentField == 2 ? RED : GRAY);
        DrawText(theme.c_str(), 210, 330, 20, BLACK);

        // Leader
        DrawText("Leader:", 200, 360, 20, BLACK);
        DrawRectangleLines(200, 390, 400, 40, currentField == 3 ? RED : GRAY);
        DrawText(leader.c_str(), 210, 400, 20, BLACK);

        // Participants
        DrawText("Participants:", 200, 430, 20, BLACK);
        DrawRectangleLines(200, 460, 400, 40, currentField == 4 ? RED : GRAY);
        DrawText(participants.c_str(), 210, 470, 20, BLACK);

        // Result
        DrawText("Result:", 200, 500, 20, BLACK);
        DrawRectangleLines(200, 530, 400, 40, currentField == 5 ? RED : GRAY);
        DrawText(result.c_str(), 210, 540, 20, BLACK);

        EndDrawing();
    }
}

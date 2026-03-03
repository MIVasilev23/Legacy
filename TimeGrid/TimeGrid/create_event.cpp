#include "create_event.h"
#include "file_manager.h"
#include "raylib.h"
#include <string>

#include "event_list.h"

void create_event(EventNode*& head)
{
    std::string name = "";
    std::string yearInput = "";

    bool typingName = true;

    while (!WindowShouldClose())
    {
        //thats for the text input
        int key = GetCharPressed();
        while (key > 0)
        {
            if (typingName) {
                name += (char)key;
            }
            else {
                yearInput += (char)key;
            }
            key = GetCharPressed();
        }

        //thats for the backspace 
        if (IsKeyPressed(KEY_BACKSPACE))
        {
            if (typingName && !name.empty())
                name.pop_back();
            else if (!typingName && !yearInput.empty())
                yearInput.pop_back();
        }

        if (IsKeyPressed(KEY_TAB))
            typingName = !typingName;

        //saves the event
        if (IsKeyPressed(KEY_ENTER) && !name.empty() && !yearInput.empty())
        {
            Event e;
            e.name = name;
            e.year = std::stoi(yearInput);

            AddEvent(head, e);
            SaveEventToFile(e);
            break;
        }

        if (IsKeyPressed(KEY_F1))
            break;

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("CREATE EVENT", 300, 40, 30, BLACK);
        DrawText("Press TAB to switch field", 250, 80, 20, DARKGRAY);
        DrawText("Press ENTER to save", 280, 110, 20, DARKGRAY);
        DrawText("F1 to return", 320, 140, 20, DARKGRAY);

        DrawText("Event Name:", 200, 200, 20, BLACK);
        DrawRectangleLines(200, 230, 400, 40, typingName ? RED : GRAY);
        DrawText(name.c_str(), 210, 240, 20, BLACK);

        DrawText("Year:", 200, 300, 20, BLACK);
        DrawRectangleLines(200, 330, 400, 40, !typingName ? RED : GRAY);
        DrawText(yearInput.c_str(), 210, 340, 20, BLACK);

        EndDrawing();
    }
}
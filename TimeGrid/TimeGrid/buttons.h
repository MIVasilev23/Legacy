#pragma once
#include <raylib.h>

class Button
{
public:
    Button(const char* imagePath, int x, int y, float scale);

    ~Button(); //Frees texture when done
    void Draw();
    bool IsPressed();

private:
    Texture2D texture;
    int x, y;
    float scale;
};
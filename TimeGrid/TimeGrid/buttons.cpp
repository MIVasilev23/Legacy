#include "buttons.h"
#include <iostream>

Button::Button(const char* imagePath, int xPos, int yPos, float s): x(xPos), y(yPos), scale(s), texture({ 0 }) // initializer list fixes warning
{
    Image img = LoadImage(imagePath);
    if (!img.data)
    {
        std::cout << "Failed to load button image: " << imagePath << std::endl;
        return;
    }

    //Resizes the image if scale is not set to 1
    if (scale != 1.0f)
        ImageResize(&img, static_cast<int>(img.width * scale), static_cast<int>(img.height * scale));

    texture = LoadTextureFromImage(img);
    UnloadImage(img);
}

Button::~Button()
{
    if (texture.id != 0)
        UnloadTexture(texture);
}

void Button::Draw()
{
    if (texture.id != 0)
        DrawTextureEx(texture, { (float)x, (float)y }, 0.0f, scale, WHITE);
}

bool Button::IsPressed()
{
    if (texture.id == 0) return false;

    //Creates rectangle representing button bounds
    Rectangle rect = {(float)x, (float)y,
                      (float)(texture.width * scale),
                      (float)(texture.height * scale)
    };

    //Returns true if mouse is inside the rectangle and if the left button pressed
    return CheckCollisionPointRec(GetMousePosition(), rect) &&
        IsMouseButtonPressed(MOUSE_LEFT_BUTTON);
}
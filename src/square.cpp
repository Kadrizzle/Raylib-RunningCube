#include "square.h"
#include <raylib.h>

square::square(float squareX, float squareY, int squareWidth, int squareHeight)
{
    x = squareX;
    y = squareY;
    width = squareWidth;
    height = squareHeight;
}

void square::moveSquare()
{
    if (IsKeyDown(KEY_UP))
    {
        y += 2.0f;
    }
    if (IsKeyDown(KEY_DOWN))
    {
        y -= 2.0f;
    }
    if (IsKeyDown(KEY_RIGHT))
    {
        x += 2.0f;
    }
    if (IsKeyDown(KEY_LEFT))
    {
        x -= 2.0f;
    }
}
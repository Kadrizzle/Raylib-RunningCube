#include "square.h"
#include <raylib.h>

square::square(float squareX, float squareY, int squareWidth, int squareHeight, Color squareColor)
{
    x = squareX;
    y = squareY;
    width = squareWidth;
    height = squareHeight;
    color = squareColor;
}

void square::movePlayer()
{
    if (IsKeyDown(KEY_W))
    {
        y -= 2.0f;
    }
    if (IsKeyDown(KEY_S))
    {
        y += 2.0f;
    }
    if (IsKeyDown(KEY_D))
    {
        x += 2.0f;
    }
    if (IsKeyDown(KEY_A))
    {
        x -= 2.0f;
    }
}

void square::drawPlayer()
{
    DrawRectangle(x, y, width, height, color);
}
#include "square.h"
#include <raylib.h>

square::square(float squareX, float squareY, int squareWidth, int squareHeight)
{
    x = squareX;
    y = squareY;
    width = squareWidth;
    height = squareHeight;
}

void square::movePlayer()
{
    if (IsKeyDown(KEY_UP))
    {
        if (mapCollisionDetection() == 2)
        {
        }
        else
        {
            y -= 2.0f;
        }
    }
    if (IsKeyDown(KEY_DOWN))
    {
        if (mapCollisionDetection() == 4)
        {
        }
        else
        {
            y += 2.0f;
        }
    }
    if (IsKeyDown(KEY_RIGHT))
    {
        if (mapCollisionDetection() == 3)
        {
        }
        else
        {
            x += 2.0f;
        }
    }
    if (IsKeyDown(KEY_LEFT))
    {
        if (mapCollisionDetection() == 1)
        {
        }
        else
        {
            x -= 2.0f;
        }
    }
}

void square::drawPlayer()
{
    DrawRectangle(x, y, width, height, BLACK);                // Outside border for player
    DrawRectangle(x + 3, y + 3, width - 6, height - 6, BLUE); // Inside of the border
}

int square::mapCollisionDetection()
{
    // 0 - no collision; 1 - left collision; 2 - top collision; 3 - right collision; 4 - bottom collision
    if (x == innerMapX)
    {
        return 1; // Left
    }
    if (y == innerMapY)
    {
        return 2; // Top
    }
    if (x + width == innerMapX + innerMapWidth)
    {
        return 3; // Right
    }
    if (y + height == innerMapY + innerMapHeight)
    {
        return 4; // Bottom
    }
    else
    {
        return 0;
    }
}
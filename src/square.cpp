#include "square.h"
#include <raylib.h>
#include <iostream>
#include <ostream>
#include <print>

square::square(float squareX, float squareY, int squareWidth, int squareHeight)
{
    x = squareX;
    y = squareY;
    width = squareWidth;
    height = squareHeight;
}

void square::clampToScreen()
{
    if (x < 0) x = 0;
    if (x > screenWidth - width) x = screenWidth - width;
    if (y < 0) y = 0;
    if (y > screenHeight - height) y = screenHeight - height;
}

void square::moveAndCollide(Map* map)
{
    float dx = 0, dy = 0;
    if (IsKeyDown(KEY_D)) dx += velocityX;
    if (IsKeyDown(KEY_A)) dx -= velocityX;
    if (IsKeyDown(KEY_S)) dy += velocityY;
    if (IsKeyDown(KEY_W)) dy -= velocityY;

    // Horizontal first
    x += dx;
    clampToScreen();
    if (dx > 0 && (map->isWall(getTopRightRow(), getTopRightColumn()) ||
                   map->isWall(getBottomRightRow(), getBottomRightColumn())))
        x = getTopRightColumn() * tileSize - width;
    else if (dx < 0 && (map->isWall(getTopLeftRow(), getTopLeftColumn()) ||
                        map->isWall(getBottomLeftRow(), getBottomLeftColumn())))
        x = (getTopLeftColumn() + 1) * tileSize;

    // Then vertical
    y += dy;
    clampToScreen();
    if (dy > 0 && (map->isWall(getBottomLeftRow(), getBottomLeftColumn()) ||
                   map->isWall(getBottomRightRow(), getBottomRightColumn())))
        y = getBottomLeftRow() * tileSize - height;
    else if (dy < 0 && (map->isWall(getTopLeftRow(), getTopLeftColumn()) ||
                        map->isWall(getTopRightRow(), getTopRightColumn())))
        y = (getTopLeftRow() + 1) * tileSize;
}

void square::movePlayer()
{
    if (IsKeyDown(KEY_W))
    {
        y -= velocityY;
    }
    if (IsKeyDown(KEY_S))
    {
        y += velocityY;
    }
    if (IsKeyDown(KEY_D)){
        x += velocityX;
    }
    if (IsKeyDown(KEY_A))
    {
        x -= velocityX;
    }
}

void square::drawPlayer()
{
    DrawRectangle(x, y, width, height, BLACK);                // Outside border for player
    DrawRectangle(x + 3, y + 3, width - 6, height - 6, BLUE); // Inside of the border
}

void square::drawEnemy()
{
    DrawRectangle(x, y, width, height, BLACK);               
    DrawRectangle(x + 3, y + 3, width - 6, height - 6, RED);   
}
 
//-All of the get functions below are for collision detection. Will need to track these values for collision detection to work properly
//-I understand that some of these are redundant, but I want to have a function for each corner's x and y position so the code
//in the collision detection will be more readable and thorough
//- Subtracting one from anything that is being added by width or height. If you don't do this then you will get phantom collisions which means
//the collision detector will think you are in two different tiles which will give the illusion that your player is teleporting
int square::getTopLeftColumn()
{
    return x / tileSize;
}

int square::getTopLeftRow()
{
    return y / tileSize;
}

int square::getTopRightColumn()
{
    return ((x + width) - 1) / tileSize;
}

int square::getTopRightRow()
{
    return y / tileSize;
}

int square::getBottomRightColumn()
{
    return ((x + width) - 1) / tileSize;
}

int square::getBottomRightRow()
{
    return ((y + height) - 1) / tileSize;
}

int square::getBottomLeftColumn()
{
    return x / tileSize;
}

int square::getBottomLeftRow()
{
    return ((y + height) - 1) / tileSize;
}


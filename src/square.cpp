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

//This function MUST run before "movePlayer" function, else it will not work
void square::mapCollisionDetection(Map* map)
{
    // The four if statements below check the very outer edge of the screen
    // Doing this so I don't get array index out of bounds for the map collision detecion logic below these
    if(x < 0)//left
    {
        x = 0;
    }
    //right
    if(x > screenWidth - width)
    {
        x = screenWidth - width;
    }
    if(y < 0)//top
    {
        y = 0;
    }
    //bottom
    if(y > screenHeight - height)
    {
        y = screenHeight - height;
    }

    //check left wall
    if(map->grid[getTopLeftRow()][getTopLeftColumn()] == tileWall ||
       map->grid[getBottomLeftRow()][getBottomLeftColumn()] == tileWall)
    {
        x = (getTopLeftColumn() + 1) * tileSize;
    }

    //check right wall
    if(map->grid[getTopRightRow()][getTopRightColumn()] == tileWall ||
       map->grid[getBottomRightRow()][getBottomRightColumn()] == tileWall)
    {
        x = (getTopRightColumn() * tileSize) - width;
    }

    //check top wall
    if(map->grid[getTopLeftRow()][getTopLeftColumn()] == tileWall ||
       map ->grid[getTopRightRow()][getTopRightColumn()] == tileWall)
    {
        y = (getTopLeftRow() + 1) * tileSize;
    }

    //check bottom wall
    if(map->grid[getBottomLeftRow()][getBottomLeftColumn()] == tileWall ||
       map->grid[getBottomRightRow()][getBottomRightColumn()] == tileWall)
    {
        y = (getBottomLeftRow() * tileSize) - height;
    }

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


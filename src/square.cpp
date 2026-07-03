#include "square.h"
#include <raylib.h>

square::square(float squareX, float squareY, int squareWidth, int squareHeight)
{
    x = squareX;
    y = squareY;
    width = squareWidth;
    height = squareHeight;
}

//This function MUST run before "movePlayer" function, else it will not work
void square::mapCollisionDetection()
{
    //Top wall
    if(y < innerMapY)
    {
        y = innerMapY;
    }

    //Bottom wall
    if(y + 30 > innerMapY + innerMapHeight)
    {
        y = (innerMapY + innerMapHeight) - 30;
    }

    //Left wall
    if(x < innerMapX)
    {
        x = innerMapX;
    }

    //Right wall
    if(x + 30 > innerMapX + innerMapWidth)
    {
        x = (innerMapX + innerMapWidth) - 30;
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

void square::moveEnemy()
{
    if(movingDown == true){
        y += velocityY + 3.0;
    }else{
        y -= velocityY + 3.0;
    }

    if(y + 30 > innerMapY + innerMapHeight){
        movingDown = false;
    }
    if(y < innerMapY){
        movingDown = true;
    }
}
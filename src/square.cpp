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
void square::mapCollisionDetection(Map* map, square* player)
{
    int coordinate;
    //The four if statements below check the very outer edge of the screen
    //Doing this so I don't get array index out of bounds for the map collision detecion logic below these
    if(player->x < 0)//left
    {
        player->x = 0;
    }
    //right
    if(player->x > screenWidth - width)
    {
        player->x = screenWidth - width;
    }
    if(player->y < 0)//top
    {
        player->y = 0;
    }
    //bottom
    if(player->y > screenHeight - height)
    {
        player->y = screenHeight - height;
    }

    //Starting r and c off at 1 and exiting 1 less than total rows and cols since we are already checking for those cases above
    //If I don't do it like this, then I'll have redundant code. Need to think of another solution later
    for(int r = 1; r < mapRows-1; r++)
    {
        for(int c = 1; c < mapCols-1; c++)
        {
            //Basically this is saying if the top left x coord of player is in said column AND the tile to the left = wall
            //left wall
            if(getTileForTopLeftX() == c && map->grid[r][c-1] == tileWall)
            {
                std::cout << "left wall" << std::endl;
                //This gives us the x coordinate we need to compare to player's position
                coordinate = c * 40;
                if(player->x < coordinate)
                {
                    player->x = coordinate;
                } 
            }
            //top wall
            if(player->getTileForTopLeftY() == r && map->grid[r-1][c] == tileWall)
            {
                std::cout << "top wall" << std::endl;
                //This gives us the y coordinate we need to compare to player's position
                coordinate = r * 40;
                if(player->y < coordinate)
                {
                    player->y = coordinate;
                }
            }
            //right wall
            if(player->getTileForBottomRightX() == c && map->grid[r][c+1] == tileWall)
            {
                std::cout << "right wall" << std::endl;
                coordinate = c * 40;
                if(player->x > coordinate)
                {
                    player->x = coordinate;
                }
            }
            //bottom wall
            if(player->getTileForBottomRightY() == r && map->grid[r+1][c] == tileWall)
            {
                std::cout << "bottom wall" << std::endl;
                coordinate = r * 40;
                if(player->y > coordinate)
                {
                    player->y = coordinate;
                }
            }
        }
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
 
//All of the get functions below are for collision detection. Will need to track these values for collision detection to work properly
int square::getBottomRightXCoord()
{
    return x + width;
}

int square::getBottomRightYCoord()
{
    return y + height;
}

//Tile size is 40 that is why I'm dividing by this number. Quick example below to get a better understanding
//Let's say the x value of the player is 110. 110/40 = 2 ---> This means the player is in tile 2 which will be col2. 
//Refer to lines 19 and 20 in map.cpp... X value is the column and Y value is the row
int square::getTileForTopLeftX()
{
    return x/40;
}

int square::getTileForTopLeftY()
{
    return y/40;
}

int square::getTileForBottomRightX()
{
    return getBottomRightXCoord()/40;
}

int square::getTileForBottomRightY()
{
    return getBottomRightYCoord()/40;
}
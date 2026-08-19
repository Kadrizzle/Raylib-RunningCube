#pragma once
#include "map.h";


// Sharing these variables from main to my square header
extern int screenWidth;
extern int screenHeight;


class square
{
public:
    float x;
    float y;
    int width;
    int height;
    float velocityX = 2.6f;
    float velocityY = 2.6f;
    bool movingDown = true;

    square(float squareX, float squareY, int squareWidth, int squareHeight);

    void movePlayer();

    void mapCollisionDetection(Map* map, square* Player); //Have to pass through the level map so player can see the walls

    void drawPlayer();

    void drawEnemy();

    int getBottomRightXCoord();

    int getBottomRightYCoord();

    int getTileForTopLeftX();

    int getTileForTopLeftY();

    int getTileForBottomRightX();

    int getTileForBottomRightY();
};

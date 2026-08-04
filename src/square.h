#pragma once
#include "map.h";


// Sharing these variables from main to my square class
extern int innerMapX;
extern int innerMapY;
extern int innerMapWidth;
extern int innerMapHeight;

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

    void mapCollisionDetection(int currentMap[mapRows][mapCols]); //Have to pass through the level map so player can see the walls

    void drawPlayer();

    void drawEnemy();

    void moveEnemy();

    int getBottomRightXCoord();

    int getBottomRightYCoord();

    int getTileForTopLeftX();

    int getTileForTopLeftY();

    int getTileForBottomRightX();

    int getTileForBottomRightY();
};

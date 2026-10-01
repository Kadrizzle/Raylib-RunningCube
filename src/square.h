#pragma once
#include "map.h"
#include "config.h"


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

    void mapCollisionDetection(Map* map); //Have to pass through the level map so player can see the walls

    void drawPlayer();

    void drawEnemy();

    void moveAndCollide(Map* map);

    void clampToScreen();


    // Remember... Column represents x ... Row represents y ...

    int getTopLeftColumn();                    int getTopRightColumn();        
    int getTopLeftRow();                       int getTopRightRow();







    int getBottomLeftColumn();                 int getBottomRightColumn();
    int getBottomLeftRow();                    int getBottomRightRow();
};

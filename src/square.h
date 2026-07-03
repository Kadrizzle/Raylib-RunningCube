#pragma once

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

    void mapCollisionDetection();

    void drawPlayer();

    void drawEnemy();

    void moveEnemy();
};

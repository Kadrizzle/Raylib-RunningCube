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
    float velocityX = 3.0f;
    float velocityY = 3.0f;

    square(float squareX, float squareY, int squareWidth, int squareHeight);

    void movePlayer();

    void mapCollisionDetection();

    void drawPlayer();
};

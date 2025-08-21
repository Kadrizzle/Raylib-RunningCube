#pragma once

// Sharing these variables from main to my square class
extern int innerMapX;
extern int innerMapY;
extern int innerMapWidth;
extern int innerMapHeight;

class square
{
private:
    float x;
    float y;
    int width;
    int height;

public:
    square(float squareX, float squareY, int squareWidth, int squareHeight);

    void movePlayer();

    int mapCollisionDetection();

    void drawPlayer();
};

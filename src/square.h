#pragma once
#include <raylib.h>

class square
{
private:
    float x;
    float y;
    int width;
    int height;
    Color color;

public:
    square(float squareX, float squareY, int squareWidth, int squareHeight, Color color);

    void movePlayer();


    bool mapCollisionDetection();


    void drawPlayer();

};

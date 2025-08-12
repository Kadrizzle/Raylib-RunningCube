#ifndef square_h
#define square_h
#include <raylib.h>

class square
{
private:
    float x;
    float y;
    int width;
    int height;
    Color RED;

public:
    square(float squareX, float squareY, int squareWidth, int squareHeight);

    void moveSquare()
    {
    }

    bool mapCollisionDetection()
    {
    }
};

#endif
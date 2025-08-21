#include <raylib.h>
#include "square.h"

// Defining these outside of main so they'll be global
int screenWidth = 1200;
int screenHeight = 600;
int mapX = (screenWidth / 6);
int mapY = (screenHeight / 6);
int mapWidth = screenWidth - (mapX * 2);
int mapHeight = screenHeight - (mapY * 2);
int innerMapX = mapX + 6;
int innerMapY = mapY + 6;
int innerMapWidth = mapWidth - 12;
int innerMapHeight = mapHeight - 12;

int main()
{
    const Color navyBlue = {0, 0, 128, 255};
    int playerWidth = 30;
    int playerHeight = 30;
    square player(innerMapX + 5, ((innerMapY + innerMapHeight) / 2) + playerHeight, playerWidth, playerHeight);

    int currentLevel = 0;

    InitWindow(screenWidth, screenHeight, "Square Runner");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        switch (currentLevel)
        {
        case 0:

            break;
        case 1:
            player.movePlayer();
            break;
        case 2:

            break;
        case 3:

            break;
        case 4:

            break;
        }

        BeginDrawing();

        switch (currentLevel)
        {
        case 0:
            DrawText("Square Runner", (screenWidth / 2) - 150, screenHeight - (screenHeight - 20), 45, navyBlue);
            DrawText("Press the enter key to start the game", (screenWidth / 2) - 300, screenHeight - (screenHeight - 80), 30, navyBlue);

            if (IsKeyPressed(KEY_ENTER))
            {
                currentLevel = 1;
            }

            break;
        case 1:
            DrawRectangle(mapX, mapY, mapWidth, mapHeight, BLACK);
            DrawRectangle(innerMapX, innerMapY, innerMapWidth, innerMapHeight, GREEN);
            player.drawPlayer();
            break;
        case 2:

            break;
        case 3:

            break;
        case 4:

            break;
        }
        ClearBackground(GRAY);
        EndDrawing();
    }

    CloseWindow();
}
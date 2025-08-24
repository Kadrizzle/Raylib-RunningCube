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
    square player(innerMapX + 10, ((innerMapY + innerMapHeight) / 2) + playerHeight + 1, playerWidth, playerHeight);

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

            // Printing my inner map and player variables to debug
            // Use this for every level to make debugging easier
            DrawText(TextFormat("Left wall: %i", innerMapX), 5, 5, 20, BLACK);
            DrawText(TextFormat("Top wall: %i", innerMapY), 5, 25, 20, BLACK);
            DrawText(TextFormat("Right wall: %i", innerMapX + innerMapWidth), 5, 45, 20, BLACK);
            DrawText(TextFormat("Bottom wall: %i", innerMapY + innerMapHeight), 5, 65, 20, BLACK);
            DrawText(TextFormat("Player x: %.2f", player.x), 5, 85, 20, BLACK);
            DrawText(TextFormat("Player y: %.2f", player.y), 5, 105, 20, BLACK);
            DrawText(TextFormat("Right: %.2f", player.x + player.width), 5, 125, 20, BLACK);
            DrawText(TextFormat("Bottom: %.2f", player.y + player.height), 5, 145, 20, BLACK);

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
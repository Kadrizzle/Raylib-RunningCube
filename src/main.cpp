#include <raylib.h>
#include "square.h"
#include <iostream>
#include <vector>

//---------------------------------------------------------------------------------------------------------------------------
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
//---------------------------------------------------------------------------------------------------------------------------
//functions()

bool enemyCollisionDetection(square enemy, square player)
{
    if(((enemy.x > player.x) && (enemy.x < (player.x + player.width)) || //left side of enemy
        (enemy.x + 30 > player.x) && (enemy.x + 30 < (player.x + player.width))) && //right side of enemy
        ((enemy.y > player.y) && (enemy.y < (player.y + 30)) || //top side of enemy
        (enemy.y + 30 > player.y) && (enemy.y + 30 < (player.y + 30)))) //bottom side of enemy
    {
        return true;
    }
    else return false;
}

int main()
{
    const Color navyBlue = {0, 0, 128, 255};

//---------------------------------------------------------------------------------------------------------------------------
    //Player variables
    int playerWidth = 30;
    int playerHeight = 30;
    square player(innerMapX + 10, ((innerMapY + innerMapHeight) / 2) + playerHeight + 1, playerWidth, playerHeight);
//---------------------------------------------------------------------------------------------------------------------------

    //Making the enemies for the first level
    int xPositionForEnemies = 291;
    int yPositionForEnemies = ((innerMapY + innerMapHeight) / 2) + playerHeight + 1;
    int enemyWidth = 30;
    int enemyHeight = 30;
    std::vector<square> enemies;

    for(int i = 0; i < 10; i++){
        square enemy(xPositionForEnemies, yPositionForEnemies, enemyWidth, enemyHeight);
        enemies.push_back(enemy);
        xPositionForEnemies+=70;
    }
//---------------------------------------------------------------------------------------------------------------------------

    int currentLevel = 0;

    InitWindow(screenWidth, screenHeight, "Square Runner");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        switch (currentLevel)
        {
        case 0:

            if (IsKeyPressed(KEY_ENTER))
            {
                currentLevel = 1;
            }
            break;
        case 1:
            player.movePlayer();
            player.mapCollisionDetection();
            for(int i = 0; i < enemies.size(); i++){
                enemies[i].moveEnemy();
                if(enemyCollisionDetection(enemies[i],player) == true)
                {
                    currentLevel = 5;
                }
            }

            //If the player hits the center of the right wall (I will be drawing this on the map to make it more clear)
            if((player.x + 30 == (innerMapX + innerMapWidth)) && (player.y + 30 > ((innerMapY + innerMapHeight) / 2) + 30 && player.y < ((innerMapY + innerMapHeight) / 2) + 60)){
                currentLevel = 2;
            }
            break;
        case 2:
            DrawText("You made it to level 2", (screenWidth / 2) - 150, screenHeight - (screenHeight - 20), 45, navyBlue);
            break;
        case 3:

            break;
        case 4:

            break;
        case 5:
            //player has died from collision
            if(IsKeyPressed(KEY_ENTER))
            {
                player.x = innerMapX + 10;
                player.y = ((innerMapY + innerMapHeight) / 2) + playerHeight + 1;
                currentLevel = 1;
            }

            break;
        }

        BeginDrawing();
        ClearBackground(GRAY);
        switch (currentLevel)
        {
        case 0:
            DrawText("Square Runner", (screenWidth / 2) - 150, screenHeight - (screenHeight - 20), 45, navyBlue);
            DrawText("Press the enter key to start the game", (screenWidth / 2) - 300, screenHeight - (screenHeight - 80), 30, navyBlue);

            break;
        case 1:
            DrawRectangle(mapX, mapY, mapWidth, mapHeight, BLACK);
            DrawRectangle(innerMapX, innerMapY, innerMapWidth, innerMapHeight, GREEN);

            //Finish line
            DrawRectangle(innerMapX + innerMapWidth, ((innerMapY + innerMapHeight) / 2) + 30, 15, 30, BLUE);

            // Printing my inner map and player variables to debug
            // Use this for every level to make debugging easier
            // DrawText(TextFormat("Left wall: %i", innerMapX), 5, 5, 20, BLACK);
            // DrawText(TextFormat("Top wall: %i", innerMapY), 5, 25, 20, BLACK);
            // DrawText(TextFormat("Right wall: %i", innerMapX + innerMapWidth), 5, 45, 20, BLACK);
            // DrawText(TextFormat("Bottom wall: %i", innerMapY + innerMapHeight), 5, 65, 20, BLACK);
            // DrawText(TextFormat("Player x: %.2f", player.x), 5, 85, 20, BLACK);
            // DrawText(TextFormat("Player y: %.2f", player.y), 5, 105, 20, BLACK);
            // DrawText(TextFormat("Right: %.2f", player.x + player.width), 5, 125, 20, BLACK);
            // DrawText(TextFormat("Bottom: %.2f", player.y + player.height), 5, 145, 20, BLACK);

            player.drawPlayer();
            for(int i = 0; i < enemies.size(); i++){
                enemies[i].drawEnemy();
            }

            break;
        case 2:

            break;
        case 3:

            break;
        case 4:

            break;

        case 5:
            DrawText("You Died", (screenWidth / 2) - 150, screenHeight - (screenHeight - 20), 60, navyBlue);
            DrawText("Press Enter to restart", (screenWidth / 2) - 150, screenHeight - (screenHeight - 20) + 50, 45, navyBlue);
            break;
        }
        EndDrawing();
    }

    CloseWindow();
}
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

bool movingUp = true;
void moveEnemyLevelTwoEven(std::vector<square>& enemies){
    for(int i = 0; i < enemies.size(); i++){
        if(i % 2 == 0){ //If enemy in vector is in an even spot
            if(movingUp == true){
                enemies[i].y -= 5.0f;
            }
            else if(movingUp == false){
                enemies[i].y += 5.0f;
            }

            if(enemies[i].y < innerMapY){
                movingUp = false;
            }
            if(enemies[i].y + 30 > innerMapY + innerMapHeight){
                movingUp = true;
            }
        }
    }
}

void moveEnemyLevelTwoOdd(std::vector<square>& enemies){
    for(int i = 0; i < enemies.size(); i++){
        if(i % 2 == 1){ //if enemy in vector is in an odd spot
            if(movingUp == true){
                enemies[i].y += 5.0f; //Odd wants to do the opposite of what even does. So, whenever moving variable is up, then odd enemies go down
            }
            else if(movingUp == false){
                enemies[i].y -= 5.0f;
            }
        }
    }
}


//---------------------------------------------------------------------------------------------------------------------------
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
        xPositionForEnemies += 70;
    }
//---------------------------------------------------------------------------------------------------------------------------

    int currentLevel = 2;

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

            //If the player hits the center of the right wall, which is the finish line (I will be drawing this on the map to make it more clear)
            if((player.x + 30 == (innerMapX + innerMapWidth)) && (player.y + 30 > ((innerMapY + innerMapHeight) / 2) + 30 && player.y < ((innerMapY + innerMapHeight) / 2) + 60)){
                currentLevel = 2;
                enemies.clear(); //Wiping the enemy vector and making a new one from scratch below

                xPositionForEnemies = 291;
                for(int i = 0; i < 10; i++){
                square enemy(xPositionForEnemies, yPositionForEnemies, enemyWidth, enemyHeight);
                enemies.push_back(enemy);
                xPositionForEnemies += 70;
            }    

                //Resetting player back to starting position
                player.x = innerMapX + 10;
                player.y = ((innerMapY + innerMapHeight) / 2) + playerHeight + 1;
                
            }
            break;
        case 2:
            player.movePlayer();
            player.mapCollisionDetection();
            moveEnemyLevelTwoEven(enemies);
            moveEnemyLevelTwoOdd(enemies);
            for(int i = 0; i < enemies.size(); i++){
                if(enemyCollisionDetection(enemies[i],player) == true){
                    currentLevel = 5;
                }
            }
            
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

            player.drawPlayer();

            for(int i = 0; i < enemies.size(); i++){
                enemies[i].drawEnemy();
            }

            break;
        case 2:
            DrawRectangle(mapX, mapY, mapWidth, mapHeight, BLACK);
            DrawRectangle(innerMapX, innerMapY, innerMapWidth, innerMapHeight, GREEN);

            //Finish line
            DrawRectangle(innerMapX + innerMapWidth, ((innerMapY + innerMapHeight) / 2) + 30, 15, 30, BLUE);

            player.drawPlayer();

            for(int i = 0; i < enemies.size(); i++){
                enemies[i].drawEnemy();
            }
            
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
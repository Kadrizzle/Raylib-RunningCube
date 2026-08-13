#include <raylib.h>
#include "square.h"
#include <iostream>
#include <vector>
#include "map.h"

//---------------------------------------------------------------------------------------------------------------------------
// Defining these outside of main so they'll be global
int screenWidth = 1200;
int screenHeight = 600;
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

int emptyLayout[mapRows][mapCols] = {
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
};


//---------------------------------------------------------------------------------------------------------------------------
int main()
{
    const Color navyBlue = {0, 0, 128, 255};
    Map editorMap(emptyLayout);
    int selectedTile = tileGameFloor;
    Map* currentMap = &editorMap;

//---------------------------------------------------------------------------------------------------------------------------
    //Player variables
    int playerWidth = 30;
    int playerHeight = 30;
    square player(100, 100, playerWidth, playerHeight);
//---------------------------------------------------------------------------------------------------------------------------

    int currentLevel = 100; // 99 is test level for all things testing

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

            break;
        case 2:
            
            break;
        case 3:

            break;
        case 4:

            break;
        case 5:
            //player has died from collision
            if(IsKeyPressed(KEY_ENTER))
            {
                currentLevel = 1;
            }

            break;

        case 99:

        break;
        
        case 100:
            currentMap = &editorMap;
            player.mapCollisionDetection(currentMap,player);
            player.movePlayer();
            DrawRectangle(300, 300, tileSize, 30, BLACK);
            DrawRectangle(120, 120, 5, tileSize, BLACK);
            // Tile selection
            if (IsKeyPressed(KEY_ONE))   selectedTile = tileEmpty;
            if (IsKeyPressed(KEY_TWO))   selectedTile = tileStart;
            if (IsKeyPressed(KEY_THREE)) selectedTile = tileEnd;
            if (IsKeyPressed(KEY_FOUR))  selectedTile = tileWall;
            if (IsKeyPressed(KEY_FIVE))  selectedTile = tileGameFloor;

            // Place / erase tiles with mouse
            {
                int mouseCol = GetMouseX() / tileSize;
                int mouseRow = GetMouseY() / tileSize;

                // Bounds check so we don't write outside the array
                if (mouseRow >= 0 && mouseRow < mapRows &&
                    mouseCol >= 0 && mouseCol < mapCols)
                {
                    if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)){
                        editorMap.grid[mouseRow][mouseCol] = selectedTile;
                        for(int i = 0; i < 35; i++){
                            std::cout << "-";
                        }
                        std::cout << std::endl;
                        for(int i = 0; i < mapRows; i++){
                            for(int j = 0; j < mapCols; j++){
                                std::cout << currentMap->grid[i][j] << " "; //Visualizing the map in terminal
                            }
                            std::cout << std::endl;
                        }
                    }
                    if (IsMouseButtonDown(MOUSE_RIGHT_BUTTON))
                        editorMap.grid[mouseRow][mouseCol] = tileEmpty;
                }
            }
            // Save / load
            if (IsKeyPressed(KEY_F5))
                editorMap.save("customlevel.txt");
            if (IsKeyPressed(KEY_F6))
                editorMap.load("customlevel.txt");

            // Back to menu
            if (IsKeyPressed(KEY_ESCAPE))
                currentLevel = 0;
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
            // DrawRectangle(mapX, mapY, mapWidth, mapHeight, BLACK);
            // DrawRectangle(innerMapX, innerMapY, innerMapWidth, innerMapHeight, GREEN);

            // //Finish line
            // DrawRectangle(innerMapX + innerMapWidth, ((innerMapY + innerMapHeight) / 2) + 30, 15, 30, BLUE);

            // player.drawPlayer();

            // for(int i = 0; i < enemies.size(); i++){
            //     enemies[i].drawEnemy();
            // }

            break;
        case 2:
            // DrawRectangle(mapX, mapY, mapWidth, mapHeight, BLACK);
            // DrawRectangle(innerMapX, innerMapY, innerMapWidth, innerMapHeight, GREEN);

            // //Finish line
            // DrawRectangle(innerMapX + innerMapWidth, ((innerMapY + innerMapHeight) / 2) + 30, 15, 30, BLUE);

            // player.drawPlayer();

            // for(int i = 0; i < enemies.size(); i++){
            //     enemies[i].drawEnemy();
            // }
            
            break;
        case 3:

            break;
        case 4:

            break;

        case 5:
            DrawText("You Died", (screenWidth / 2) - 150, screenHeight - (screenHeight - 20), 60, navyBlue);
            DrawText("Press Enter to restart", (screenWidth / 2) - 150, screenHeight - (screenHeight - 20) + 50, 45, navyBlue);
            break;

        case 99:
            DrawRectangle(200, 200, tileSize, 5, BLACK);
            DrawRectangle(200, 240, tileSize, 5, BLACK);
            DrawRectangle(240, 200, 5, tileSize, BLACK);
            DrawRectangle(200,200,5, 40, BLACK);
            break;


        case 100:
            currentMap->draw();
            player.drawPlayer();

            // Show which tile is selected
            DrawText(TextFormat("Selected tile: %i", selectedTile), 5, 5, 20, BLACK);
            DrawText("1=Empty 2=Start 3=End 4=Wall 5=Game Floor", 5, 25, 20, BLACK);
            DrawText("F5=Save  F6=Load  ESC=Menu", 5, 45, 20, BLACK);

            // Highlight tile under mouse
            {
                int mouseCol = GetMouseX() / tileSize;
                int mouseRow = GetMouseY() / tileSize;
                DrawRectangleLines(mouseCol * tileSize, mouseRow * tileSize, tileSize, tileSize, WHITE);
            }
            break; 
        }
        EndDrawing();
    }

    CloseWindow();
}
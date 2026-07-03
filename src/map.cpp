#include "map.h"
#include <raylib.h>
#include <cstring>
#include <fstream>
#include <iostream>


Map::Map(int layout[mapRows][mapCols]){
    memcpy(grid, layout, sizeof(grid));//Copying layout's memory location into grid's location in memory
                                       //The last parameter will be the amount of bytes that we allocate.
                                       //In this case it will be the size of grid (technically layout)
}

void Map::draw(){ //nested for loop that is looping from left to right, then going to the next row
    for(int row = 0; row < mapRows; row++)
    {
        for(int col = 0; col < mapCols; col++)
        {
            int tileX = col * tileSize; //Position of x for tile
            int tileY = row * tileSize; //Position of y for tile

            //To get a better understanding of the placement before the tile is drawn,
            //the first row will print each tile with a y coordinate of 0!
            //This is because row(0) * tileSize(20) = 0
            //row(1) * tileSize(20) = 20
            //... so on and so forth
            switch(grid[row][col]){
                case 1: DrawRectangle(tileX, tileY, tileSize, tileSize, GRAY); break; //empty
                case 2: DrawRectangle(tileX, tileY, tileSize, tileSize, BLUE); break; //start
                case 3: DrawRectangle(tileX, tileY, tileSize, tileSize, BLUE); break; //end
                case 4: 
                    //bottom wall ... if value is above the wall
                    if((grid[row-1][col] == 2) || (grid[row-1][col] == 3) || (grid[row-1][col] == 5)){
                        DrawRectangle(tileX, tileY, tileSize, 5, BLACK);
                        std::cout << "you drew a bottom wall" << std::endl;
                    }
                    
                    //top wall ... if the value is below the wall
                    if((grid[row+1][col] == 2) || (grid[row+1][col] == 3) || (grid[row+1][col] == 5)){
                        DrawRectangle(tileX, tileY+40, tileSize, 5, BLACK);
                        std::cout << "you drew a top wall" << std::endl;
                    }

                    //left wall ... 
                    if((grid[row][col+1] == 2) || (grid[row][col+1] == 3) || (grid[row][col+1] == 5)){
                        DrawRectangle(tileX+40, tileY, 5, tileSize, BLACK);
                        std::cout << "you drew a left wall" << std::endl;
                    }

                    //right wall ... 
                    if((grid[row][col-1] == 2) || (grid[row][col-1] == 3) || (grid[row][col-1] == 5)){
                        DrawRectangle(tileX, tileY, 5, tileSize, BLACK);
                        std::cout << "you drew a right wall" << std::endl;
                    }
                    break; //wall
                case 5: DrawRectangle(tileX, tileY, tileSize, tileSize, GREEN); break; //gamefloor
            }
        }
    }
}

// bool Map::isWall(int row, int col){
//     return grid[row][col] == 1;
// }

void Map::save(const char* filename)
{
    std::ofstream file(filename);
    for (int row = 0; row < mapRows; row++)
    {
        for (int col = 0; col < mapCols; col++)
            file << grid[row][col] << " ";
        file << "\n";
    }
}
   
void Map::load(const char* filename)
{
    std::ifstream file(filename);
    for (int row = 0; row < mapRows; row++)
        for (int col = 0; col < mapCols; col++)
            file >> grid[row][col];
}


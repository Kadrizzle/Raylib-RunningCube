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
                case tileEmpty: DrawRectangle(tileX, tileY, tileSize, tileSize, GRAY); break; //empty
                case tileStart: DrawRectangle(tileX, tileY, tileSize, tileSize, BLUE); break; //start
                case tileEnd: DrawRectangle(tileX, tileY, tileSize, tileSize, BLUE); break; //end
                case tileWall: 
                    //top wall (relative to the value below 4)
                    if(row > 0 && (grid[row-1][col] == 2 || grid[row-1][col] == 3 || grid[row-1][col] == 5)){
                        DrawRectangle(tileX, tileY, tileSize, 5, BLACK);
                        //std::cout << "you drew a bottom wall" << std::endl;
                    }
                    
                    //bottom wall (relative to the value above 4)
                    if(row < mapRows-1 && (grid[row+1][col] == 2 || grid[row+1][col] == 3 || grid[row+1][col] == 5)){
                        DrawRectangle(tileX, tileY + tileSize - 5, tileSize, 5, BLACK);
                        //std::cout << "you drew a top wall" << std::endl;
                    }

                    //left wall (relative to value to the right of 4) 
                    if(col < mapCols-1 && (grid[row][col+1] == 2 || grid[row][col+1] == 3 || grid[row][col+1] == 5)){
                        DrawRectangle(tileX + tileSize - 5, tileY, 5, tileSize, BLACK);
                        //std::cout << "you drew a left wall" << std::endl;
                    }

                    //right wall (relative to value to the left of 4)
                    if(col > 0 && (grid[row][col-1] == 2 || grid[row][col-1] == 3 || grid[row][col-1] == 5)){
                        DrawRectangle(tileX, tileY, 5, tileSize, BLACK);
                        //std::cout << "you drew a right wall" << std::endl;
                    }
                    break; //wall
                case tileGameFloor: DrawRectangle(tileX, tileY, tileSize, tileSize, GREEN); break; //gamefloor
            }
        }
    }
}

bool Map::isWall(int row, int col)
{
    if (row < 0 || row >= mapRows || col < 0 || col >= mapCols) return true;
    return grid[row][col] == tileWall;
}

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


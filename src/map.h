#pragma once
#include <raylib.h>

enum TileType {
    tileEmpty = 1,
    tileStart = 2,
    tileEnd = 3,
    tileWall = 4,
    tileGameFloor = 5
};

//To be able to draw on the whole entire window I'll need to take the map width and map height and run some math on those numbers
const int tileSize = 40; //This number will more than likely change once I start drawing the map out
const int mapRows = 15;
const int mapCols = 30;
//For now I will make the maps 30x30 unless I see need for a change later... they are now changed to 30 rows and 15 cols because the tile size is now 40

class Map{

public:
    int grid[mapRows][mapCols];

    Map(int layout[mapRows][mapCols]);//Remember this is only for the initialization of the map object
                                      //After that, these values are gone and need to be handled by grid above

    void draw();
    bool isWall(int row, int col);
    void save(const char* filename);
    void load(const char* filename);
};

//Here are some notes so I can visualize how this class is going to look in main

//map level3(layout[30][30]) 

//You will have to manually add enum values to the map BUT every map will be the same size in the backend, but on the front end all of the maps will look different
//with that being said, you can have const values for your map width and height
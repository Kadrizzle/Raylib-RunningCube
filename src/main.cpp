#include <raylib.h>
#include "square.h"

int main()
{
    const Color navyBlue = {0, 0, 128, 255};

    constexpr int screenWidth = 800;
    constexpr int screenHeight = 600;
    square player(100, 100, 50, 50, BLUE);

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
            DrawText("Hello, you're on level 1", 50, 50, 50, navyBlue);
            player.drawPlayer();
            break;
        case 2:

            break;
        case 3:

            break;
        case 4:

            break;
        }
        ClearBackground(BEIGE);
        EndDrawing();
    }

    CloseWindow();
}
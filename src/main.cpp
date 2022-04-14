#include "common.hpp"
#include "draw.hpp"
#include "loader.hpp"

int main()
{
    SetConfigFlags(FLAG_VSYNC_HINT);
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, GAME_NAME);
    Game game;
    game.storedDialogue = new dialogue[1024]; //nombre de ligne de text a stocker

    game.gameState=0;
    game.showDebug = false;

    readAllFile((const char*)"dialogue.txt",(const char*)"save.txt", game);

    SetTargetFPS(60);

    while (!WindowShouldClose() && game.isRunning)
    {
        updateGame(game);
        drawGame(game);
        /* printf("UNF");
        BeginDrawing();
        ClearBackground(RED);
        EndDrawing(); */
        game.deltaTime = GetFrameTime();
    }
    game.clearData();
    delete[] game.storedDialogue;
    CloseWindow();

    return 0;
}
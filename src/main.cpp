#include "common.hpp"
#include "draw.hpp"
#include "loader.hpp"

int main()
{
    SetConfigFlags(FLAG_VSYNC_HINT);
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, GAME_NAME);
    common::Game game;
    game.storedDialogue = new common::dialogue[1024]; //nombre de ligne de text a stocker

    game.gameState=0;
    game.showDebug = false;

    fileManagement::readAllFile((const char*)"dialogue.txt",(const char*)"save.txt", game);

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        draw::updateGame(game);
        draw::drawGame(game);
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
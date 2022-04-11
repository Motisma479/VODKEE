#include "draw.hpp"
#include "utils.hpp"

void drawEnter(common::Game &game);
void updateEnter(common::Game &game);

void drawIntro(common::Game &game);
void updateIntro(common::Game &game);

void drawStart(common::Game &game);
void drawOverWorld(common::Game &game);
void drawFight(common::Game &game);
void drawGOver(common::Game &game);
void updateFight(common::Game &game);

void draw::updateGame(common::Game &game){
    switch (game.gameState)
    {
    case 0:
        updateMainMenu(game);
        break;
    case 1:
        updateIntro(game);
        break;
    case 2:
        
        break;
    case 3:
        
        break;
    case 4:
        updateFight(game);
        break;
    case 5:
        break;
    default:
        break;
    }
}

void draw::drawGame(common::Game &game){
    switch (game.gameState)
    {
    case 0:
        drawMainMenu(game);
        break;
    case 1:
        drawIntro(game);
        break;
    case 2:
        drawStart(game);
        
        break;
    case 3:
        drawOverWorld(game);
        
        break;
    case 4:
        drawFight(game);
        break;
    case 5:
        drawGOver(game);
        break;
    default:
        break;
    }
}

// Draw Enter Menu
void drawMainMenu(common::Game &game){
    BeginDrawing();
        ClearBackground(RED);
        DrawTextureEx(game.getTextureById(1),{0,0},0,2,WHITE);
        DrawText("[PRESS 2 OR ENTER]",  220, 350, 20, LIGHTGRAY);
        if (game.showDebug)
        {
            DrawFPS(0,0);
            DrawText(TextFormat("deltaTime: %f", game.deltaTime), 10, 450, 20, LIGHTGRAY);
        }
    EndDrawing();
}
//Update Enter Menu
void updateMainMenu(common::Game &game){
    if (IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_KP_ENTER)){
        game.gameState = 1;
    } 
}


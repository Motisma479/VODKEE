#include "draw.hpp"
#include "ui.hpp"

void drawMainMenu(Game &game);
void updateMainMenu(Game &game);

void drawScene(Game &game);
void updateScene(Game &game);

void updateGame(Game &game){
    switch (game.gameState)
    {
    case 0:
        updateMainMenu(game);
        break;
    default:
        updateScene(game);
        break;
    }
}

void drawGame(Game &game){
    switch (game.gameState)
    {
    case 0:
        drawMainMenu(game);
        break;
    default:
        drawScene(game);
        break;
    }
}

// Draw Enter Menu
Button Play(2,{(SCREEN_WIDTH/2.f)-(461/2.f),SCREEN_HEIGHT-108-150,461,108},WHITE,"Play Demo",40,GRAY);
void drawMainMenu(Game &game){
    BeginDrawing();
        ClearBackground(RED);
        DrawTexture(game.getTextureById(0),0,0,WHITE);
        DrawTextureEx(game.getTextureById(1),{(SCREEN_WIDTH/2.f)-((game.getTextureById(1).width*0.25f)/2.f),0},0,0.25f,WHITE);

        Play.draw(game);

        if (game.showDebug)
        {
            DrawFPS(0,0);
            DrawText(TextFormat("deltaTime: %f", game.deltaTime), 0, 15, 20, DARKGREEN);
            DrawText(TextFormat("gameState: %d", game.gameState), 0, 30, 20, DARKGREEN);
        }
    EndDrawing();
}
//Update Enter Menu
void updateMainMenu(Game &game){
    Play.update();
    if (Play.isPressed)
        game.gameState = 1;
}

// Draw Enter Menu
Dialogue dialogue(4,{(SCREEN_WIDTH/2.f)-(857/2.f),SCREEN_HEIGHT-325,857,325},WHITE,40,GRAY);
bool Init = true;
bool isTalking = true;
void drawScene(Game &game){
    if (Init){
        dialogue.initText(game.storedDialogue);
        Init = false;
    }
    BeginDrawing();
        ClearBackground(RED);
        DrawTexture(game.getTextureById(game.backGroundId),0,0,WHITE);
        DrawTextureEx(game.getTextureById(1),{(SCREEN_WIDTH/2.f)-((game.getTextureById(1).width*0.25f)/2.f),0},0,0.25f,WHITE);

        if (isTalking)
        {
            dialogue.draw(game);
            //DrawTextureEx(game.getTextureById(4),,0,0.35,WHITE);
        }
        

        if (game.showDebug)
        {
            DrawFPS(0,0);
            DrawText(TextFormat("deltaTime: %f", game.deltaTime), 0, 15, 20, DARKGREEN);
            DrawText(TextFormat("gameState: %d", game.gameState), 0, 30, 20, DARKGREEN);
            DrawText(TextFormat("textFrame: %d", game.textFrame), 0, 45, 20, DARKGREEN);
        }
    EndDrawing();
}
//Update Enter Menu
void updateScene(Game &game){
    dialogue.update();
    if (IsKeyPressed(KEY_ENTER) || dialogue.isPressed)
    {
        dialogue.mState++;
        game.textFrame = 0;
    }
}
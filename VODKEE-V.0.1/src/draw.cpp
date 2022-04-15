#include "draw.hpp"
#include "ui.hpp"
#include "iostream"

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
Button Button1(2,{(SCREEN_WIDTH/2.f)-(461/2.f),SCREEN_HEIGHT/2-108-150,461,108},WHITE,"Play Demo",40,GRAY);
Button Button2(2,{(SCREEN_WIDTH/2.f)-(461/2.f),SCREEN_HEIGHT/2-108,461,108},WHITE,"Play Demo",40,GRAY);
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
        if(game.P1)
            DrawTextureEx(game.getTextureById(15),{75,0},0,0.4f,WHITE);
        if(game.P2)
            DrawTextureEx(game.getTextureById(16),{775,0},0,0.4f,WHITE);
        if(game.P3)
            DrawTextureEx(game.getTextureById(17),{(SCREEN_WIDTH/2.f)-((game.getTextureById(1).width*0.25f)/2.f),0},0,0.4f,WHITE);
        

        if (isTalking)
        {
            dialogue.draw(game);
            //DrawTextureEx(game.getTextureById(4),,0,0.35,WHITE);
        }
        if (dialogue.haveButton){
            Button2.draw(game);
            Button1.draw(game);
        }

        if (game.showDebug)
        {
            DrawFPS(0,0);
            DrawText(TextFormat("deltaTime: %f", game.deltaTime), 0, 15, 20, DARKGREEN);
            DrawText(TextFormat("gameState: %d", game.gameState), 0, 30, 20, DARKGREEN);
            DrawText(TextFormat("textFrame: %d", game.textFrame), 0, 45, 20, DARKGREEN);
            //DrawText(TextFormat("nbOfButton: %ld", ), 0, 60, 20, DARKGREEN);
            //std::cout << game.button1Name.length() << std::endl;
            DrawText(TextFormat("valueOfRedirictionOfBt1: %d", dialogue.button1Redirection), 0, 75, 20, DARKGREEN);
            DrawText(TextFormat("nameOfBt1: %s", game.button1Name.c_str()), 0, 90, 20, DARKGREEN);
            DrawText(TextFormat("valueOfRedirictionOfBt2: %d", dialogue.button2Redirection), 0, 105, 20, DARKGREEN);
            DrawText(TextFormat("nameOfBt2: %s", game.button2Name.c_str()), 0, 120, 20, DARKGREEN);
        }
    EndDrawing();
}
//Update Enter Menu
void updateScene(Game &game){
    
    dialogue.update();
    if (dialogue.haveButton)
    {
        //isTalking = false;
        Button2.changeText(game.button2Name.c_str());
        Button2.update();
        if(Button2.isPressed){
            dialogue.mState= dialogue.button2Redirection;
            game.textFrame = 0;
            dialogue.haveButton = false;
            game.button1Name.clear();
            game.button2Name.clear();
        }
        Button1.changeText(game.button1Name.c_str());
        Button1.update();
        if(Button1.isPressed){
            dialogue.mState= dialogue.button1Redirection;
            game.textFrame = 0;
            dialogue.haveButton = false;
            game.button1Name.clear();
            game.button2Name.clear();
        }
    }
    else{
        isTalking = true;
    }
    
    if ((IsKeyPressed(KEY_ENTER) || dialogue.isPressed)&& !dialogue.haveButton)
    {
        dialogue.mState++;
        game.textFrame = 0;
    }
}
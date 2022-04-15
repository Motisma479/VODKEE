#include "common.hpp"
#include "dataName.hpp"

Game::Game(){
    //Load your texture here.
    for (size_t i = 0; i < TEXTURE_COUNT; i++)
    {
        Texture2D* t1 = new Texture2D;
        *t1 = LoadTexture(textureNames[i]);
        GameTexture.emplace_back(t1);
    }
    

    //Load your font here.
    for (size_t i = 0; i < FONT_COUNT; i++)
    {
        Font* f1 = new Font;
        *f1 = LoadFont(fontNames[i]);
        GameFont.emplace_back(f1);
    }
}
Game::~Game(){}
void Game::clearData(){
    //unload textures
    for (size_t i = 0; i < GameTexture.size(); i++)
    {
        UnloadTexture(*GameTexture[i]);
        delete GameTexture[i];
    }

    //unload fonts
    for (size_t i = 0; i < GameFont.size(); i++)
    {
        UnloadFont(*GameFont[i]);
        delete GameFont[i];
    }
}
Texture2D Game::getTextureById(int Id){
    return *GameTexture[Id];
}
Font Game::getFontById(int Id){
    return *GameFont[Id];
}
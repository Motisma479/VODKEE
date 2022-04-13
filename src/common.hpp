#pragma once
#define SCREEN_WIDTH 1547
#define SCREEN_HEIGHT 870
#define GAME_NAME "Vodkee"

#include <raylib.h>
#include <vector>
#include <string>


struct dialogue
{
	std::string text;
};


class Game
{
public:
	Game();
	~Game();
	bool isRunning = true;
	size_t 			gameState; // 0 Start Screen; 1 Intro; 2 OverWorld; 3 Fight;4 GameOver
	void clearData();
	Texture2D getTextureById(int Id);
	Font getFontById(int Id);

	bool	showDebug;
	int 	textFrame = 0;
	float 	deltaTime;
	dialogue* 		storedDialogue;

	int backGroundId = 0;
	char*     nameToDisplay;
private:
	std::vector<Texture2D*> GameTexture;
	std::vector<Font*> GameFont;
};

#pragma once
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define GAME_NAME "Vodkee"

#include <raylib.h>
#include <vector>
#include <string>

namespace common{
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
	private:
        std::vector<Texture2D*> GameTexture;
        std::vector<Font*> GameFont;
	};
}
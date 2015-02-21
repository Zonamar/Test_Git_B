#pragma once

#include <SDL/SDL.h>
#include <GL/glew.h>
#include "sprite.h"
#include "glslProgram.h"


enum class GameState{
					PLAY,
					EXIT,



					num_GameStates};


class MainGame
{
public:
	MainGame();
	~MainGame();

	void run();

	

private:

	SDL_Window * _window;
	int _screenWidth;
	int _screenHeight;
	GameState _gameState;

	Sprite _sprite;

	glslProgram _colorProgram;


	void initSystems();
	void processInput();
	void gameLoop();
	void drawGame();
	void initShaders();


};


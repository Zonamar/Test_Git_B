#pragma once

#include <SDL/SDL.h>
#include <GL/glew.h>
#include "sprite.h"
#include "glslProgram.h"
#include "glTexture.h"
#include <vector>


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
	
	std::vector<Sprite*> _sprites;

	


	glslProgram _colorProgram;

	float _time;


	void initSystems();
	void processInput();
	void gameLoop();
	void drawGame();
	void initShaders();


};


#pragma once

#include <SDL/SDL.h>
#include <GL/glew.h>


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

	void processInput();
	void gameLoop();

	void initSystems();
};


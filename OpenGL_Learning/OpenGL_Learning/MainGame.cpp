#include "MainGame.h"
#include <iostream>


MainGame::MainGame()
{
	_window = nullptr;
	_screenHeight = 768;
	_screenWidth  = 1024;
	_gameState = GameState::PLAY;


	
}


MainGame::~MainGame()
{
}

void MainGame::run()
{
	initSystems();
	gameLoop();


}

void MainGame::initSystems()
{
	SDL_Init(SDL_INIT_EVERYTHING);				// init SDL

	_window = SDL_CreateWindow("myGameEng", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _screenWidth, _screenHeight, SDL_WINDOW_OPENGL);



}

void MainGame::processInput()
{

	SDL_Event evnt;

	while (SDL_PollEvent(&evnt))
	{
		switch (evnt.type)
		{
		case SDL_QUIT:
			_gameState = GameState::EXIT;
			break;
		
		
		case SDL_MOUSEMOTION:
			std::cout << evnt.motion.x << "x   " << evnt.motion.y << "y  " << std::endl;


			break;


		default:
			break;
		}


	}




}
void MainGame::gameLoop()
{
	while (_gameState != GameState::EXIT)
	{
		processInput();

	}

}
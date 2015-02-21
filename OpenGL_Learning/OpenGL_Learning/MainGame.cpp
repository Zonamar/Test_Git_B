#include "MainGame.h"


MainGame::MainGame()
{
	_window = nullptr;
	_screenHeight = 768;
	_screenWidth  = 1024;

	
}


MainGame::~MainGame()
{
}

void MainGame::run()
{
	initSystems();

}

void MainGame::initSystems()
{
	SDL_Init(SDL_INIT_EVERYTHING);				// init SDL

	_window = SDL_CreateWindow("myGameEng", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _screenWidth, _screenHeight, SDL_WINDOW_OPENGL);



}
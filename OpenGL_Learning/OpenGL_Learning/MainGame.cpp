#include "MainGame.h"

#include <iostream>
#include <string>
#include <Zongine/MyError.h>
#include <Zongine\Zongine.h>


MainGame::MainGame() : _screenHeight(768), _screenWidth(1024), _gameState(GameState::PLAY), _time(0), _maxFps(60.0f)
{



	
}


MainGame::~MainGame()
{
}

void MainGame::run()
{
	initSystems();

	_sprites.push_back(new Zongine::Sprite());
	_sprites.back()->init(-1.0f, -1.0f, 1.0f, 1.0f, "Textures/JimmyJump/PNG/CharacterRight_Standing.png");

	_sprites.push_back(new Zongine::Sprite());
	_sprites.back()->init(0.0f, 0.0f, 1.0f, 1.0f, "Textures/JimmyJump/PNG/CharacterRight_Standing.png");

	_sprites.push_back(new Zongine::Sprite());
	_sprites.back()->init(-1.0f, 0.0f, 1.0f, 1.0f, "Textures/JimmyJump/PNG/CharacterRight_Standing.png");

	
	//_playerTexture = ImageLoader::loadPNG("Textures/JimmyJump/PNG/CharacterRight_Standing.png");

	gameLoop();


}

void MainGame::initSystems()
{
	


	_window.create("Game Engine", _screenWidth, _screenHeight, 0);


	initShaders();
}

void MainGame::initShaders()
{
	_colorProgram.compileShaders("Shaders/colorShading.vert", "Shaders/colorShading.frag");
	_colorProgram.addAttribute("vertexPosition");
	_colorProgram.addAttribute("vertexColor");
	_colorProgram.addAttribute("vertexUV");
	_colorProgram.linkShaders();

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
		float startTick = SDL_GetTicks();
		processInput();
		_time += 0.01;
		drawGame();
		calculatetFPS();

		static int frameCounter = 0;

		frameCounter++;
		if (frameCounter == 10)
		{
			std::cout << "fps:" << _fps << "\n";
			frameCounter = 0;
		}

		float frameTicks = SDL_GetTicks() - startTick;

		if (1000.0f / _maxFps > frameTicks)
		{
			SDL_Delay((1000.0f / _maxFps) - frameTicks);
		}

	}

}

void MainGame::drawGame()
{
	
	
	
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	

	_colorProgram.use();
	glActiveTexture(GL_TEXTURE0);
	
	GLint textureLocation = _colorProgram.getUniformLocation("mySampler");

	glUniform1i(textureLocation, 0);


	GLint timeLocation = _colorProgram.getUniformLocation("time");

	glUniform1f(timeLocation, _time);


	for (int i = 0; i < _sprites.size(); i++)
	{
		_sprites[i]->draw();

	}

	_colorProgram.unUse();

	glBindTexture(GL_TEXTURE_2D, 0);


	_window.swapBuffer();

}

void MainGame::calculatetFPS()
{

	static const int NUM_SAMPLES = 100;
	static float frameTimes[NUM_SAMPLES];
	static int currentFrame = 0;
	float frameTimeAverage=0;



	static float prevTicks = SDL_GetTicks();
	float currentTicks;

	currentTicks = SDL_GetTicks();

	_frameTime = currentTicks - prevTicks;

	prevTicks = currentTicks;


	frameTimes[currentFrame % NUM_SAMPLES] = _frameTime;

	int count;
	currentFrame++; 

	if (currentFrame < NUM_SAMPLES)
	{
		count = currentFrame;
	}
else
{
	count = NUM_SAMPLES;
}

	for (int i = 0; i < count; i++)
	{
		frameTimeAverage += frameTimes[i];

	}
	frameTimeAverage /= count;

	if (frameTimeAverage >0){
		_fps = 1000.0f / frameTimeAverage;

	}
	else{
		_fps = 60;
	}
	
	

}
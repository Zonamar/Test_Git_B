#pragma once

#include <SDL/SDL.h>
#include <GL/glew.h>
#include <Zongine/sprite.h>
#include <Zongine/glslProgram.h>
#include <Zongine/glTexture.h>
#include <Zongine/Window.h>
#include <Zongine/Camera2D.h>
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

	Zongine::Window _window;
	int _screenWidth;
	int _screenHeight;
	GameState _gameState;

	Zongine::Sprite _sprite;
	
	std::vector<Zongine::Sprite*> _sprites;


	


	Zongine::glslProgram _colorProgram;
	Zongine::Camera2D _camera;


	float _time;
	float _fps;
	float _frameTime;
	float _maxFps;

	void initSystems();
	void processInput();
	void gameLoop();
	void drawGame();
	void initShaders();
	void calculatetFPS();




};


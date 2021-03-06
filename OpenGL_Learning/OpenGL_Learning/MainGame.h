#pragma once

#include <SDL/SDL.h>
#include <GL/glew.h>

#include <Zongine/Zongine.h>
#include <Zongine/glslProgram.h>
#include <Zongine/glTexture.h>
#include <Zongine/sprite.h>
#include <Zongine/Window.h>
#include <Zongine/SpriteBatch.h>
#include <Zongine/Camera2D.h>
#include <vector>
#include <Zongine/InputManager.h>
#include <Zongine/Timing.h>
#include "Bullet.h"



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

	Zongine::SpriteBatch _spriteBatch;


	Zongine::glslProgram _colorProgram;
	Zongine::Camera2D _camera;

	Zongine::InputManager _inputManager;
	Zongine::FpsLimiter _fpsLimiter;

	std::vector<Bullet> _Bullets;



	float _time;
	float _fps;
	
	float _maxFps;

	void initSystems();
	void processInput();
	void gameLoop();
	void drawGame();
	void initShaders();
	void calculatetFPS();




};


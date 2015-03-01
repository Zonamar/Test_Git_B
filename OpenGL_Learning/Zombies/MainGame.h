#pragma once

#include <Zongine/Window.h>
#include <Zongine/GLSLProgram.h>
#include <Zongine/Camera2D.h>
#include <Zongine/InputManager.h>
#include <Zongine/SpriteBatch.h>
#include <Zongine/Timing.h>


enum GameState {
			PLAY,
			EXIT,




			NUM_GAME_STATES
};



class MainGame
{
public:
    MainGame();
    ~MainGame();

    /// Runs the game
    void run();

private:
    /// Initializes the core systems
    void initSystems();

    /// Initializes the shaders
    void initShaders();

    /// Main game loop for the program
    void gameLoop();

    /// Handles input processing
    void processInput();

    /// Renders the game
    void drawGame();
	
	// Gets Level Map
	void getLevel(int LevelNumber);


    /// Member Variables
    Zongine::Window _window; ///< The game window
    
    Zongine::glslProgram _textureProgram; ///< The shader program

    Zongine::InputManager _inputManager; ///< Handles input

    Zongine::Camera2D _camera; ///< Main Camera

	Zongine::SpriteBatch _spriteBatch;  // Handles Sprite drawing

	Zongine::FpsLimiter _fpsLimiter;  // holds the FPS to a set amount;

	int _screenHeight, _screenWidth;

	float _time;

	float _fps;

	const float MAX_FPS = 60;

	GameState _gameState;

};


#pragma once

#include <Zongine/Window.h>
#include <Zongine/GLSLProgram.h>
#include <Zongine/Camera2D.h>
#include <Zongine/InputManager.h>

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

    /// Member Variables
    Zongine::Window _window; ///< The game window
    

    Zongine::glslProgram _textureProgram; ///< The shader program

    Zongine::InputManager _inputManager; ///< Handles input

    Zongine::Camera2D _camera; ///< Main Camera
};


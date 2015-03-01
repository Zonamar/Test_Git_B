#include "MainGame.h"

#include <Zongine/Zongine.h>

#include <SDL/SDL.h>
#include <iostream>

MainGame::MainGame() :  _screenWidth(1024),
						_screenHeight(768), 
						_time(0.0f), 
						_fps(0.0f)
{
 
}

MainGame::~MainGame() {
    // IMPLEMENT THIS!
}

void MainGame::run() {
    
	initSystems();

	_gameState = GameState::PLAY;

	gameLoop();
	
}

void MainGame::initSystems() 
{
	Zongine::init();

	_camera.init(_screenWidth, _screenHeight);

	_window.create("Zombie Game", _screenWidth, _screenHeight, 0);

	initShaders();

	_spriteBatch.init();

	_fpsLimiter.init(MAX_FPS);


}

void MainGame::initShaders() {
    // Compile our color shader
    _textureProgram.compileShaders("Shaders/textureShading.vert", "Shaders/textureShading.frag");
    _textureProgram.addAttribute("vertexPosition");
    _textureProgram.addAttribute("vertexColor");
    _textureProgram.addAttribute("vertexUV");
    _textureProgram.linkShaders();
}

void MainGame::gameLoop() {
   
	while (_gameState == GameState::PLAY)
	{
		_fpsLimiter.beginFrame();

		processInput();

		drawGame();

		_fps = _fpsLimiter.endFrame();
		
	}


}

void MainGame::processInput() {
    SDL_Event evnt;
    //Will keep looping until there are no more events to process
    while (SDL_PollEvent(&evnt)) {
        switch (evnt.type) {
            case SDL_QUIT:
				_gameState = GameState::EXIT;
                break;
            case SDL_MOUSEMOTION:
                _inputManager.setMouseCords(evnt.motion.x, evnt.motion.y);
                break;
            case SDL_KEYDOWN:
                _inputManager.pressKey(evnt.key.keysym.sym);
                break;
            case SDL_KEYUP:
                _inputManager.releaseKey(evnt.key.keysym.sym);
                break;
            case SDL_MOUSEBUTTONDOWN:
                _inputManager.pressKey(evnt.button.button);
                break;
            case SDL_MOUSEBUTTONUP:
                _inputManager.releaseKey(evnt.button.button);
                break;
        }
    }
}

void MainGame::drawGame() {

	

    // Set the base depth to 1.0
    glClearDepth(1.0);
    // Clear the color and depth buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	_textureProgram.use();

	glActiveTexture(GL_TEXTURE0);

	// Load Sampler to the Shader
	GLint textureLoc = _textureProgram.getUniformLocation("mySampler");

	glUniform1i(textureLoc, 0);

	// Load the shift from the Camera Location to shader
	GLint pLoc = _textureProgram.getUniformLocation("P");

	glm::mat4 cameraMatrix = _camera.getCameraMatrix();

	glUniformMatrix4fv(pLoc, 1, GL_FALSE, &(cameraMatrix[0][0]));
	

	// Start Drawing
	_spriteBatch.begin();



	// Add Sprites to be drawn here
	  




	// End Drawying phase
	_spriteBatch.end();

	_spriteBatch.renderBatch();
	
	
	_textureProgram.unUse();


	glBindTexture(GL_TEXTURE_2D, 0);


    // Swap our buffer and draw everything to the screen!
    _window.swapBuffer();



}

void MainGame::getLevel(int LevelNumber)
{

}
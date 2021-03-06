#include "MainGame.h"

#include <iostream>
#include <string>
#include <Zongine/MyError.h>
#include <Zongine/ResourceManager.h>
#include <Zongine/glTexture.h>



MainGame::MainGame() : _screenHeight(768), _screenWidth(1024), _gameState(GameState::PLAY), _time(0), _maxFps(60.0f)
{

	_camera.init(_screenWidth, _screenHeight);
	

	
}


MainGame::~MainGame()
{
}

void MainGame::run()
{
	initSystems();


	//_playerTexture = ImageLoader::loadPNG("Textures/JimmyJump/PNG/CharacterRight_Standing.png");

	gameLoop();


}

void MainGame::initSystems()
{
	
	

	Zongine::init();


	_window.create("Game Engine", _screenWidth, _screenHeight,0);


	initShaders();

	_spriteBatch.init();
	_fpsLimiter.init(_maxFps);


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
	const float CAMERA_SPEED = 10;
	const float SCALE_SPEED = 0.1f;
	SDL_Event evnt;

	while (SDL_PollEvent(&evnt))
	{
		switch (evnt.type)
		{
		case SDL_QUIT:
			_gameState = GameState::EXIT;
			break;
		case SDL_KEYDOWN:
			_inputManager.pressKey(evnt.key.keysym.sym);
			break;
		case SDL_KEYUP:
			_inputManager.releaseKey(evnt.key.keysym.sym);
			break;
		case SDL_MOUSEMOTION:
			_inputManager.setMouseCords(evnt.motion.x, evnt.motion.y);

			break;
		case SDL_MOUSEBUTTONDOWN:
			_inputManager.pressKey(evnt.button.button);
			break;
		case SDL_MOUSEBUTTONUP:
			_inputManager.releaseKey(evnt.button.button);
			break;
		default:
			break;
		}


	}

	if (_inputManager.isKeyPressed(SDLK_w))
	{
		_camera.setPosition(_camera.getPosition() + glm::vec2(0.0f, CAMERA_SPEED));
	}
	if (_inputManager.isKeyPressed(SDLK_s))
	{
		_camera.setPosition(_camera.getPosition() + glm::vec2(0.0f, -CAMERA_SPEED));
	}
	if (_inputManager.isKeyPressed(SDLK_a))
	{
		_camera.setPosition(_camera.getPosition() + glm::vec2(-CAMERA_SPEED, 0.0f));
	}
	if (_inputManager.isKeyPressed(SDLK_d))
	{
		_camera.setPosition(_camera.getPosition() + glm::vec2(CAMERA_SPEED, 0.0f));
	}
	if (_inputManager.isKeyPressed(SDLK_q))
	{
		_camera.setScale(_camera.getScale() + SCALE_SPEED);
	}
	if (_inputManager.isKeyPressed(SDLK_e))
	{
		_camera.setScale(_camera.getScale() - SCALE_SPEED);
	}
	if (_inputManager.isKeyPressed(SDL_BUTTON_LEFT))
	{
		glm::vec2 mouseCoords = _inputManager.getMouseCords();
		mouseCoords = _camera.convertScreenToWorld(mouseCoords);

		glm::vec2 playerPosition(0.0f);

		glm::vec2 direction = mouseCoords - playerPosition;

		direction = glm::normalize(direction);

		_Bullets.emplace_back(playerPosition, direction, 8.0f, 1000);



		std::cout << mouseCoords.x << "x  " << mouseCoords.y << "y " << std::endl;
	}

}
void MainGame::gameLoop()
{
	while (_gameState != GameState::EXIT)
	{
		_fpsLimiter.beginFrame();

		processInput();
		_time += 0.01f;

		_camera.update();
		
		for (int i = 0; i < _Bullets.size(); )
		{
			if (_Bullets[i].update() == true)
			{
				_Bullets[i] = _Bullets.back();
				_Bullets.pop_back();

			}
			else
			{
				i++;
			}
		}

		drawGame();

		_fps = _fpsLimiter.endFrame();

		static int frameCounter = 0;

		frameCounter++;

		if (frameCounter == 10000)
		{
			std::cout << "fps:" << _fps << "\n";
			frameCounter = 0;
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


	GLint pLocation = _colorProgram.getUniformLocation("P");

	glm::mat4 cameraMatrix = _camera.getCameraMatrix();

	glUniformMatrix4fv(pLocation, 1, GL_FALSE, &(cameraMatrix[0][0]));

	_spriteBatch.begin();
	
	glm::vec4 pos(0.0f, 0.0f, 50.0f, 50.0f);
	glm::vec4 uv(0.0f, 0.0f, 1.0f, 1.0f);
	static Zongine::GLTexture texture = Zongine::ResourceManager::getTexture("Textures/JimmyJump/PNG/CharacterRight_Standing.png");
	Zongine::Color color;

	color.r = 255;
	color.g = 255;
	color.b = 255;
	color.a = 255;


		_spriteBatch.draw(pos, uv, texture.id, 0.0f, color);
	

		for (int i = 0; i < _Bullets.size(); i++)
		{
			_Bullets[i].draw(_spriteBatch);

		}
	_spriteBatch.end();

	_spriteBatch.renderBatch();



	_colorProgram.unUse();

	glBindTexture(GL_TEXTURE_2D, 0);


	_window.swapBuffer();

}

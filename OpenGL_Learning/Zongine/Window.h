#pragma once

#include<SDL\SDL.h>
#include<GL\glew.h>
#include<string>


namespace Zongine{
	enum WindowFlags
	{
		INVISIBLE = 0x1,
		FULLSCREEN = 0x2,
		BOARDERLESS = 0x4,





	};



	class Window
	{
	public:
		Window();
		~Window();

		int create(std::string windowName, int screenWidth, int screenHeight, unsigned int currentFlags);
		int GetScreenWidth(){ return _screenWidth; };
		int GetScreenHeight(){ return _screenHeight; };
		void swapBuffer();


	private:

		SDL_Window* _sdlWindow;
		int _screenWidth, _screenHeight;



	};

}
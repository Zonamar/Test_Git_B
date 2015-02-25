#include "Timing.h"
#include <SDL\SDL.h>

namespace Zongine{




	FpsLimiter::FpsLimiter()
	{

	}

	void FpsLimiter::init(float fps)
	{
		setMaxFps(fps);

	}

	void FpsLimiter::beginFrame()
	{
		_startTicks = SDL_GetTicks();


	}

	float FpsLimiter::endFrame()
	{
		calculateFPS();

		float frameTicks = SDL_GetTicks() - _startTicks;

		if (1000.0f / _maxFps > frameTicks)
		{
			SDL_Delay((1000.0f / _maxFps) - frameTicks);
		}

		return _fps;


	}


	void FpsLimiter::setMaxFps(float fps)
	{
		_maxFps = fps;

	}
	void FpsLimiter::calculateFPS()
	{
		static const int NUM_SAMPLES = 100;
		static float frameTimes[NUM_SAMPLES];
		static int currentFrame = 0;
		float frameTimeAverage = 0;



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










}
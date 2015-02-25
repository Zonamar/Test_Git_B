#pragma once

namespace Zongine{


	class FpsLimiter
	{
	public :

		FpsLimiter();
		
		void init(float fps);
		
		void beginFrame();
		
		float endFrame();

		void setMaxFps(float fps);


	private:

		void calculateFPS();

		float _maxFps;
		float _fps;
		float _frameTime;

		unsigned int _startTicks;


	};






}
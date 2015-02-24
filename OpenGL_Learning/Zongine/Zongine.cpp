#include <SDL/SDL.h>
#include <GL/glew.h>

#include "Zongine.h"


namespace Zongine{

	int init() {
		SDL_Init(SDL_INIT_EVERYTHING);				// init SDL

		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

		return 0;
	}
}
#pragma once

#include "glTexture.h"
#include <string>


namespace Zongine{
	class ImageLoader
	{
	public:

		static GLTexture loadPNG(std::string filePath);

	};

}
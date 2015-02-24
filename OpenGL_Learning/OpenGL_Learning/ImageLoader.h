#pragma once

#include "glTexture.h"
#include <string>
class ImageLoader
{
public:

	static GLTexture loadPNG(std::string filePath);

};


#pragma once

#include "TextureCashe.h"
#include "glTexture.h"

namespace Zongine{
	class ResourceManager
	{
	public:
		static GLTexture getTexture(std::string texturePath);



	private:

		static TextureCashe _textureCashe;



	};

}
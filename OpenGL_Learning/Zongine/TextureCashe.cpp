#include "TextureCashe.h"
#include "ImageLoader.h"
#include <iostream>

namespace Zongine{
	TextureCashe::TextureCashe()
	{
	}


	TextureCashe::~TextureCashe()
	{
	}

	GLTexture TextureCashe::getTexture(std::string filePath)
	{

		_textureMap.find(filePath);


		auto mit = _textureMap.find(filePath);

		if (mit == _textureMap.end())
		{
			GLTexture newTexture = ImageLoader::loadPNG(filePath);

			std::pair<std::string, GLTexture> newPair(filePath, newTexture);

			_textureMap.insert(newPair);

			std::cout << "Loaded Texture into Cashe" << std::endl;

			return newTexture;
		}

	//	std::cout << "Got Texture" << std::endl;
		return mit->second;


	}
}
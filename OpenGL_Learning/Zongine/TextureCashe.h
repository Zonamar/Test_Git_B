#pragma once

#include<map>
#include"glTexture.h"

class TextureCashe
{
public:
	TextureCashe();
	~TextureCashe();

	GLTexture getTexture(std::string filePath);


private:

	std::map<std::string, GLTexture> _textureMap;


};


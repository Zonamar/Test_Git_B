#include "ResourceManager.h"

TextureCashe ResourceManager::_textureCashe;

GLTexture ResourceManager::getTexture(std::string texturePath)
{
	return _textureCashe.getTexture(texturePath);

}
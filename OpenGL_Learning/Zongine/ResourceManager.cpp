#include "ResourceManager.h"

namespace Zongine{
	TextureCashe ResourceManager::_textureCashe;

	GLTexture ResourceManager::getTexture(std::string texturePath)
	{
		return _textureCashe.getTexture(texturePath);

	}
}
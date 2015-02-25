#include "InputManager.h"
namespace Zongine{

	InputManager::InputManager() : _mouseCoords(0.0f)
	{
	}


	InputManager::~InputManager()
	{
	}

	void InputManager::pressKey(unsigned int keyId)
	{
		_keyMap[keyId] = true;
		
	}

	void InputManager::releaseKey(unsigned int keyId)
	{
		_keyMap[keyId] = false;
	}

	void InputManager::setMouseCords(float x, float y)
	{
		_mouseCoords.x = x;
		_mouseCoords.y = y;

	}

	const glm::vec2 InputManager::getMouseCords()
	{
		return _mouseCoords;
	}

	bool InputManager::isKeyPressed(unsigned int keyId)
	{
		auto it = _keyMap.find(keyId);

		if (it != _keyMap.end())
		{
			return it->second;
		}

		return false;

	}



}
#pragma once

#include <unordered_map>
#include <glm\glm.hpp>

namespace Zongine{


	class InputManager
	{
	public:
		InputManager();
		~InputManager();


		void pressKey(unsigned int keyId);
		void releaseKey(unsigned int keyId);
		void setMouseCords(float x, float y);
		const glm::vec2 getMouseCords();

		bool isKeyPressed(unsigned int keyId);

		

	private:

		std::unordered_map<unsigned int, bool> _keyMap;

		glm::vec2 _mouseCoords;

	};

}
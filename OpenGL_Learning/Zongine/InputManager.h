#pragma once

#include <unordered_map>
namespace Zongine{


	class InputManager
	{
	public:
		InputManager();
		~InputManager();


		void pressKey(unsigned int keyId);
		void releaseKey(unsigned int keyId);

		bool isKeyPressed(unsigned int keyId);

	private:

		std::unordered_map<unsigned int, bool> _keyMap;

	};

}
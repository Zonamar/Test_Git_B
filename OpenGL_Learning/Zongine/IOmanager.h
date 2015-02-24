#pragma once
#include<vector>
#include<string>


namespace Zongine{
	class IOmanager
	{
	public:

		static bool readFileToBuffer(std::string filePath, std::vector<unsigned char> &buffer);


	};

}
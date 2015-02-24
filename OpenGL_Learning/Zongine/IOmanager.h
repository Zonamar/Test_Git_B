#pragma once
#include<vector>
#include<string>
class IOmanager
{
public:

	static bool readFileToBuffer(std::string filePath, std::vector<unsigned char> &buffer);


};


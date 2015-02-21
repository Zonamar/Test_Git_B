
#include"MainGame.h"
#include<iostream>


int main(int argc, char ** argv)
{
	MainGame myGame;

	myGame.run();


	std::cout << "Enter any key to quit..." << std::endl;
	int a;
	std::cin >> a;

	return 0;

}
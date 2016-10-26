#include "game.h"

#include <conio.h>
#include <iostream>

bool Game::run()
{
	char key = ' ';
	frameCount = 0;

	while(key != 'q')
	{
		while (!getInput(&key))
		{		
			timerUpdate();
		}
		std::cout << "You pressed: " << key << std::endl;
	}

	std::cout << frameCount << std::endl;
	std::cout <<  "End of the game" << key << std::endl;
	system("pause");
	return true;
}

bool Game::getInput(char* c)
{
	if(kbhit())
	{
		*c = getch();
		return true;
	}

	return false;
}

void Game::timerUpdate()
{
	frameCount++;
}
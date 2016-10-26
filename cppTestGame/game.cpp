#include "game.h"

#include <conio.h>
#include <Windows.h>
#include <iostream>

using namespace std;

#define GAME_SPEED 33.33 // game speed - 30 FPS

bool Game::run()
{
	drawArea.createSprite(0, '$');	

	player = new Sprite(&drawArea, 0);

	char key = ' ';

	startTime = timeGetTime();
	frameCount = 0;
	lastTime = 0;

	posx = 0;

	while(key != 'q')
	{
		while (!getInput(&key))
		{		
			timerUpdate();			
		}
		//cout << "You pressed: " << key << endl;
	}

	delete player;

	cout << frameCount / ((timeGetTime() - startTime) / 1000) << " FPS " << endl;
	cout <<  "End of the game " << endl;
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
	double currentTime = timeGetTime() - lastTime;

	if (currentTime < GAME_SPEED)
		return;
	
	player->move(1, 0);

	frameCount++;

	lastTime = timeGetTime();
}
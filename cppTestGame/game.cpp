#include "game.h"

#include <conio.h>
#include <Windows.h>
#include <iostream>

using namespace std;

#define GAME_SPEED 33.33 // game speed - 30 FPS

bool Game::run()
{
	level = new Level(&drawArea, 30, 20);

	drawArea.createBackgroundTile(TILE_EMPTY, ' ');
	drawArea.createBackgroundTile(TILE_WALL, 219);

	drawArea.createSprite(SPRITE_PLAYER, 'o');	
	drawArea.createSprite(SPRITE_ENEMY, '@');

	player = new Character(level, &drawArea, 0);

	level->draw();
	level->addPlayer(player);
	level->addEnemies(3);

	char key = ' ';

	startTime = timeGetTime();
	frameCount = 0;
	lastTime = 0;

	posx = 0;

	player->move(0, 0);

	while(key != 'q')
	{
		while (!getInput(&key))
		{		
			timerUpdate();			
		}

		level->keyPress(key);

		//cout << "You pressed: " << key << endl;
	}

	delete player;

	//cout << frameCount / ((timeGetTime() - startTime) / 1000) << " FPS " << endl;
	//cout <<  "End of the game " << endl;
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

	level->update();

	frameCount++;

	lastTime = timeGetTime();
}
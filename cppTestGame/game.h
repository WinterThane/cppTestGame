#pragma once
#ifndef GAME_H
#define GAME_H

#include "drawEngine.h"
#include "character.h"

class Game
{
public:
	bool run(void);

protected:
	bool getInput(char *c);
	void timerUpdate(void);

private:
	Character *player;

	double frameCount;
	double startTime;
	double lastTime;

	int posx;

	DrawEngine drawArea;
};

#endif

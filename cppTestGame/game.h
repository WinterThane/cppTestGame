#pragma once
#ifndef GAME_H
#define GAME_H

#include "drawEngine.h"
#include "level.h"
#include "mage.h"

class Game
{
public:
	bool run(void);

protected:
	bool getInput(char *c);
	void timerUpdate(void);

private:
	Mage *player;
	Level *level;

	double frameCount;
	double startTime;
	double lastTime;

	int posx;

	DrawEngine drawArea;
};

#endif

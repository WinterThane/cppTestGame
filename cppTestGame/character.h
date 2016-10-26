#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H

#include "sprite.h"

class Character : public Sprite
{
public:
	Character(DrawEngine *de, int s_index, float x = 1, float y = 1, int lives = 3, char up_key = 'w', char up_down = 's', char up_left = 'a', char up_right = 'd');

	virtual bool keyPress(char c);

protected:
	char upKey;
	char downKey;
	char leftKey;
	char rightKey;
};

#endif
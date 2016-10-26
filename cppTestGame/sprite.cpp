#include "sprite.h"

Sprite::Sprite(DrawEngine* de, int s_index, float x, float y, int i_lives)
{
	drawArea = de;
	pos.x = x;
	pos.y = y;

	spriteIndex = s_index;

	numLives = i_lives;

	facinDirection.x = 1;
	facinDirection.y = 0;

	classID = SPRITE_CLASSID;
}

Sprite::~Sprite()
{
	erase(pos.x, pos.y); //erase dead sprite
}

vector Sprite::getPosition(void)
{
	return pos;
}

float Sprite::getX(void)
{
	return pos.x;
}
float Sprite::getY(void)
{
	return pos.y;
}

void Sprite::addLives(int num)
{
	numLives += num;
}

int Sprite::getLives()
{
	return numLives;
}

bool Sprite::isAlive()
{
	return (numLives > 0);
}

bool Sprite::move(float x, float y)
{
	erase(pos.x, pos.y);

	pos.x += x;
	pos.y += y;

	facinDirection.x = x;
	facinDirection.y = y;

	draw(pos.x, pos.y);

	return true;
}

void Sprite::draw(float x, float y)
{
	drawArea->drawSprite(spriteIndex, (int)x, (int)y);
}

void Sprite::erase(float x, float y)
{
	drawArea->eraseSprite((int)x, (int)y);
}
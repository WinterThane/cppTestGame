#pragma once
#ifndef LEVEL_H
#define LEVEL_H

#include "drawEngine.h"
#include <list>

using std::list;

class Character;
class Sprite;

enum
{
	SPRITE_PLAYER,
	SPRITE_ENEMY,
	SPRITE_FIREBALL
};

enum
{
	TILE_EMPTY,
	TILE_WALL
};

class Level
{
public:
	Level(DrawEngine *de, int width = 30, int height = 20);
	~Level();

	void addPlayer(Character *p);
	void update(void);
	void draw(void);
	bool keyPress(char c);

	friend class Sprite;

	void addEnemies(int num);
	void addNPC(Sprite *spr);	

protected:
	void createLevel(void);

private:
	int width;
	int height;

	char **level;

	Character *player;
	DrawEngine *drawArea;

public:
	list <Sprite *> npc;
	list <Sprite *>::iterator Iter;
};

#endif

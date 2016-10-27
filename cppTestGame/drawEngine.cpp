#include "drawEngine.h"

#include <Windows.h>
#include <wincon.h>
#include <iostream>

using namespace std;

DrawEngine::DrawEngine(int xSize, int ySize)
{
	screenWidth = xSize;
	screenHeight = ySize;

	cusrorVisibility(false); //set cursor visibility to false

	map = 0;
}

DrawEngine::~DrawEngine()
{
	cusrorVisibility(true);	//set cursor visibility to true

	gotoxy(0, screenHeight);
}

int DrawEngine::createSprite(int index, char c)
{
	if (index >= 0 && index < 16)
	{
		spriteImage[index] = c;
		return index;
	}

	return -1;
}

void DrawEngine::deleteSprite(int index)
{
	// don't need it
}

void DrawEngine::drawSprite(int index, int posx, int posy)
{
	gotoxy(posx, posy);	//go to correct location	
	cout << spriteImage[index];	// draw the image
}

void DrawEngine::setMap(char **data)
{
	map = data;
}

void DrawEngine::createBackgroundTile(int index, char c)
{
	if(index >= 0  && index < 16)
	{
		tileImage[index] = c;
	}
}


void DrawEngine::drawBackground()
{
	if(map)
	{
		for(int y = 0; y < screenHeight; y++)
		{
			gotoxy(0, y);

			for(int x = 0; x < screenWidth; x++)
			{
				cout << tileImage[map[x][y]];
			}
		}
	}
}

void DrawEngine::eraseSprite(int posx, int posy)
{
	gotoxy(posx, posy);
	cout << ' ';
}

void DrawEngine::gotoxy(int x, int y)
{
	HANDLE output_handle;
	COORD pos;

	pos.X = x;
	pos.Y = y;
	output_handle = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleCursorPosition(output_handle, pos);
}


void DrawEngine::cusrorVisibility(bool visibility)
{
	HANDLE output_handle;
	CONSOLE_CURSOR_INFO ccInfo;

	ccInfo.dwSize = 1;
	ccInfo.bVisible = visibility;

	output_handle = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleCursorInfo(output_handle, &ccInfo);
}
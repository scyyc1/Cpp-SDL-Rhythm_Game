#pragma once
#include "..\header.h"
#include "..\BaseEngine.h"
#include "..\TileManager.h"
#include "note.h"
class LongNote :
	public note {

public:
	LongNote(BaseEngine* pEngine,
		int xStart, int yStart, int index,
		int iWidth, int iHeight, bool useTopLeftFor00,
		int track, TileManager* pTileManager, int length);
	~LongNote();

	void virtDraw();
	//void virtDoUpdate(int iCurrentTime);
	note* selfCopy();
private:
	void drawInitial(int X, int Y, int FX, int FY, int track);
	int length;
};

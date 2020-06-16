#pragma once
#include "..\header.h"
#include "note.h"

class SingleNote :
	public note {

public:
	SingleNote(BaseEngine* pEngine,
		int xStart, int yStart, int index,
		int iWidth, int iHeight, bool useTopLeftFor00,
		int track, TileManager* pTileManager);
	~SingleNote();


};
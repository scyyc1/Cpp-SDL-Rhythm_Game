#include "..\header.h"
#include "SingleNote.h"

SingleNote::SingleNote(BaseEngine* pEngine, 
	int xStart, int yStart, int index, 
	int iWidth, int iHeight, bool useTopLeftFor00, 
	int track, TileManager* pTileManager)
	: note(pEngine, xStart, yStart, index, iWidth, iHeight, 
		useTopLeftFor00, track, pTileManager)
{
	
}

SingleNote::~SingleNote() {};


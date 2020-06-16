#pragma once
#include "header.h"
#include "TileManager.h"

class Scyyc1TileManager :
	public TileManager
{
public:
	Scyyc1TileManager();
	~Scyyc1TileManager();
	void virtDrawTileAt(BaseEngine* pEngine, DrawingSurface* pSurface, 
		int iMapX, int iMapY, 
		int iStartPositionScreenX, int iStartPositionScreenY) const override;

	// Copy from demo tutorial, ramdomly change the colour of all tiles
	unsigned int changeColour()
	{
		this->iColour = (unsigned int)((rand() & 0xf00) << 12)
			+ (unsigned int)((rand() & 0xf0) << 8)
			+ (unsigned int)((rand() & 0xf) << 4);
		return iColour;
	};

private:
	unsigned int iColour;				// Indicate the colour of tiles
};


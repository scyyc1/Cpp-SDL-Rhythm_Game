#include "Scyyc1TileManager.h"
#include "Scyyc1Engine.h"
#include "BaseEngine.h"

constexpr auto QUADRILATERAL = 4;

Scyyc1TileManager::Scyyc1TileManager() : TileManager(100, 100, 10, 4)
{
	this->iColour = 0xffffff;
}

Scyyc1TileManager::~Scyyc1TileManager()
{
}

void Scyyc1TileManager::virtDrawTileAt(BaseEngine* pEngine, DrawingSurface* pSurface, int iMapX, int iMapY, int iStartPositionScreenX, int iStartPositionScreenY) const
{
	int x1 = iStartPositionScreenX + 40;
	int y1 = iStartPositionScreenY + 30;

	int x2 = iStartPositionScreenX + 60;
	int y2 = iStartPositionScreenY + 50;

	int x3 = iStartPositionScreenX + 40;
	int y3 = iStartPositionScreenY + 70;

	pSurface->drawLine(x1, y1, x2, y2, iColour);
	pSurface->drawLine(x2, y2, x3, y3, iColour);
}

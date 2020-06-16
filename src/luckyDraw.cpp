#include "luckyDraw.h"

void luckyDraw::virtDrawTileAt(BaseEngine* pEngine, DrawingSurface* pSurface, int iMapX, int iMapY, int iStartPositionScreenX, int iStartPositionScreenY) const
{
	int drawRightX = iStartPositionScreenX + getTileWidth() - 1;
	int drawRightY = iStartPositionScreenY + getTileHeight() - 1;

	pSurface->drawRectangle(iStartPositionScreenX, iStartPositionScreenY, 
		drawRightX, drawRightY, 0xffffff);
	//pSurface->drawRectangle(iStartPositionScreenX + RECTANGLE_OFFSET, iStartPositionScreenY + RECTANGLE_OFFSET,
	//	drawRightX - RECTANGLE_OFFSET, drawRightY - RECTANGLE_OFFSET, 0x000000);
	pictures[getMapValue(iMapX, iMapY)].renderImage(pSurface,
		0, 0, iStartPositionScreenX+25, iStartPositionScreenY+25,
		pictures[getMapValue(iMapX, iMapY)].getWidth(), 
		pictures[getMapValue(iMapX, iMapY)].getHeight());
}

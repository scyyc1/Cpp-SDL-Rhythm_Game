#include "header.h"
#include "lifeManager.h"

constexpr auto RECTANGLE_OFFSET = 3;

lifeManager::lifeManager() : TileManager(30, 30, 8, 2)
{
	this->life = m_iMapWidth * m_iMapHeight;
	image= ImageManager::get()->getImagebyURL("./images/life.png", true, true);
}

lifeManager::~lifeManager()
{
}

void lifeManager::virtDrawTileAt(
	BaseEngine* pEngine,
	DrawingSurface* pSurface,
	int iMapX, int iMapY,
	int iStartPositionScreenX, int iStartPositionScreenY) const
{

	int drawRightX = iStartPositionScreenX + getTileWidth() - 1;
	int drawRightY = iStartPositionScreenY + getTileHeight() - 1;

	pSurface->drawRectangle(iStartPositionScreenX, iStartPositionScreenY, drawRightX, drawRightY, 0xffffff);

	switch (getMapValue(iMapX, iMapY)) 
	{
	case 0:
		pSurface->drawRectangle(iStartPositionScreenX + RECTANGLE_OFFSET, iStartPositionScreenY + RECTANGLE_OFFSET,
			drawRightX - RECTANGLE_OFFSET, drawRightY - RECTANGLE_OFFSET, 0x000000);
		break;
	case 1:
		image.renderImage(pSurface,
			0, 0, iStartPositionScreenX, iStartPositionScreenY,
			image.getWidth(), image.getHeight());
	}
}
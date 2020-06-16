#include "speedController.h"
#include "Scyyc1Engine.h"

speedController::speedController(BaseEngine* pEngine, int xStart, int yStart, int iWidth, int iHeight, bool useTopLeftFor00)
	: DisplayableObject(xStart, yStart, pEngine, iWidth, iHeight, useTopLeftFor00)
{
	this->isDragged = false;
	this->isClick = false;
	this->isLocked = false;
}

speedController::~speedController()
{
}

void speedController::virtDraw()
{
	int drawX = m_iCurrentScreenX + m_iStartDrawPosX;
	int drawY = m_iCurrentScreenY + m_iStartDrawPosY;
	int drawFinalX = m_iCurrentScreenX - m_iStartDrawPosX;
	int drawFinalY = m_iCurrentScreenY - m_iStartDrawPosY;

	switch ((int)isDragged)
	{
	case 0:
		getEngine()->drawForegroundRectangle(drawX, drawY, drawFinalX, drawFinalY, 0xffffff);
		break;
	case 1:
		getEngine()->drawForegroundRectangle(drawX, drawY, drawFinalX, drawFinalY, 0x00ffff);
		break;
	}
	
	getEngine()->drawForegroundRectangle(drawX + OVAL_OFFSET, drawY + OVAL_OFFSET, drawFinalX - OVAL_OFFSET, drawFinalY - OVAL_OFFSET, 0x000000);
}


bool speedController::isValidClick(int iX, int iY)
{

	int drawX = m_iCurrentScreenX + m_iStartDrawPosX;
	int drawY = m_iCurrentScreenY + m_iStartDrawPosY;
	int drawLeftX = m_iCurrentScreenX - m_iStartDrawPosX;
	int drawLeftY = m_iCurrentScreenY - m_iStartDrawPosY;

	if (iX < drawX)
	{
		return false;
	}
	if (iY < drawY)
	{
		return false;
	}
	if (iX >= drawLeftX)
	{
		return false;
	}
	if (iY >= drawLeftY)
	{
		return false;
	}
	return true;
}

#include "note.h"
#include "..\BaseEngine.h"
#include "..\Scyyc1Engine.h"
#include "..\MovementPosition.h"
#include "..\states\State.h"

double note::speed = 0.0;

note::note(BaseEngine* pEngine, int xStart, int yStart, 
	int index, int iWidth, int iHeight, 
	bool useTopLeftFor00, int track, TileManager* pTileManager)
	: DisplayableObject(xStart, yStart, pEngine, iWidth, iHeight, useTopLeftFor00)
{
	this->track = track;
	this->startPosX = (double)xStart;
	this->startPosY = (double)yStart;
	this->moveX = (double)xStart;
	this->moveY = (double)yStart;
	this->m_iCurrentScreenX = xStart;
	this->m_iCurrentScreenY = yStart;
	this->m_pTileManager = pTileManager;
	this->index = index;
	string fruit;
	switch (track) {
	case 0: fruit = "s_cherry"; break;
	case 1: fruit = "s_lemon"; break;
	case 2: fruit = "s_watermelon"; break;
	case 3: fruit = "s_kiwi"; break;
	}

	string buff = "./images/" + fruit + ".png";
	image = ImageManager::get()->getImagebyURL(buff, true, true);
}

note::~note(){}


void note::virtDraw()
{
	int drawX = m_iCurrentScreenX + m_iStartDrawPosX;
	int drawY = m_iCurrentScreenY + m_iStartDrawPosY;
	int drawFinalX = m_iCurrentScreenX - m_iStartDrawPosX;
	int drawFinalY = m_iCurrentScreenY - m_iStartDrawPosY;
	
	drawInitial(drawX, drawY, drawFinalX, drawFinalY, this->track);
}


void note::virtDoUpdate(int iCurrentTime)
{
	moveX += speed;

	m_iCurrentScreenX = (int)moveX;

	if (iCurrentTime == -1)
	{
		m_iCurrentScreenX = (int)startPosX;
		moveX = startPosX;
	}

	if (m_pTileManager->isValidTilePosition(m_iCurrentScreenX, m_iCurrentScreenY))
	{
		int iMapX = m_pTileManager->getMapXForScreenX(m_iCurrentScreenX);
		int iMapY = m_pTileManager->getMapYForScreenY(m_iCurrentScreenY);
		m_pTileManager->setAndRedrawMapValueAt(iMapX, iMapY, rand(), getEngine(), getEngine()->getBackgroundSurface());
	}
}

note* note::selfCopy()
{
	return new note(getEngine(), m_iCurrentScreenX, m_iCurrentScreenY, index, m_iDrawWidth, m_iDrawHeight, false, track, m_pTileManager);
}

void note::drawInitial(int X, int Y, int FX, int FY, int track)
{
	image.renderImage(getEngine()->getForegroundSurface(),
		0, 0, X+ OVAL_OFFSET, Y+ OVAL_OFFSET,
		image.getWidth(), image.getHeight());
}

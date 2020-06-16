#include "DoubleNote.h"

DoubleNote::DoubleNote(BaseEngine* pEngine, int xStart, int yStart, 
	int index, int iWidth, 
	int iHeight, bool useTopLeftFor00, 
	int track, TileManager* pTileManager)
	: note(pEngine, xStart, yStart, index, iWidth, iHeight,
		useTopLeftFor00, track, pTileManager)
{
	this->ano_track = 0;
	while (this->track == this->ano_track)
		ano_track = rand() % 4;

	n1 = new note(pEngine, xStart, yStart,
		index, iWidth, iHeight, useTopLeftFor00, track, pTileManager);
	n2 = new note(pEngine, xStart, yStart +ano_track*NOTE_SIZE,
		index, iWidth, iHeight, useTopLeftFor00, ano_track, pTileManager);
}

DoubleNote::~DoubleNote(){}

note* DoubleNote::selfCopy()
{
	DoubleNote* n=new DoubleNote(getEngine(), m_iCurrentScreenX, m_iCurrentScreenY, index, m_iDrawWidth, m_iDrawHeight, false, track, m_pTileManager);
	n->setAnoTrack(ano_track);
	return n;
}

void DoubleNote::virtDraw() 
{
	int drawX = m_iCurrentScreenX + m_iStartDrawPosX;
	int drawY = m_iCurrentScreenY + m_iStartDrawPosY;
	int drawFinalX = m_iCurrentScreenX - m_iStartDrawPosX;
	int drawFinalY = m_iCurrentScreenY - m_iStartDrawPosY;

	getEngine()->drawForegroundOval(drawX,drawY, drawFinalX, drawFinalY,0xffffff);
}
//
//void DoubleNote::drawInitial(int X, int Y, int FX, int FY, int track)
//{
//	getEngine()->drawForegroundOval(X, Y, FX, FY, 0xFFFFFF);
//	getEngine()->drawForegroundOval(X + OVAL_OFFSET, Y + OVAL_OFFSET, FX - OVAL_OFFSET, FY - OVAL_OFFSET, 0x00000000);
//	getEngine()->drawForegroundRectangle(X, Y + 45, FX, FY - 45, 0x00ffffff);
//}



#include "LongNote.h"

using namespace std;

LongNote::LongNote(BaseEngine* pEngine, int xStart, int yStart,
	int index, int iWidth,
	int iHeight, bool useTopLeftFor00,
	int track, TileManager* pTileManager, int length)
	: note(pEngine, xStart, yStart, index, iWidth, iHeight,
		useTopLeftFor00, track, pTileManager)
{
	this->length = length;
}

LongNote::~LongNote() {}

void LongNote::virtDraw()
{
	int drawX = m_iCurrentScreenX + m_iStartDrawPosX;
	int drawY = m_iCurrentScreenY + m_iStartDrawPosY;
	int drawFinalX = m_iCurrentScreenX - m_iStartDrawPosX;
	int drawFinalY = m_iCurrentScreenY - m_iStartDrawPosY;

	drawInitial(drawX, drawY, drawFinalX, drawFinalY, this->track);
}

void LongNote::drawInitial(int X, int Y, int FX, int FY, int track)
{
	getEngine()->drawForegroundOval(X - length, Y, FX - length, FY, 0xffffff);
	getEngine()->drawForegroundRectangle(X - length + NOTE_SIZE / 2, Y, X + NOTE_SIZE / 2, FY, 0xffffff);
	getEngine()->drawForegroundOval(X, Y, FX, FY, 0xffffff);
	getEngine()->drawForegroundOval(X + OVAL_OFFSET, Y + OVAL_OFFSET, FX - OVAL_OFFSET, FY - OVAL_OFFSET, 0x000000);
}

note* LongNote::selfCopy()
{
	return new LongNote(getEngine(), m_iCurrentScreenX, m_iCurrentScreenY, index, m_iDrawWidth, m_iDrawHeight, false, track, m_pTileManager, length);
}
#include "Button.h"
using namespace std;

void Button::virtDraw()
{
	int drawX = m_iCurrentScreenX + m_iStartDrawPosX;
	int drawY = m_iCurrentScreenY + m_iStartDrawPosY;
	int drawFinalX = m_iCurrentScreenX - m_iStartDrawPosX;
	int drawFinalY = m_iCurrentScreenY - m_iStartDrawPosY;

	isDragged?
		getEngine()->drawForegroundRectangle(drawX, drawY, drawFinalX, drawFinalY, 0xffffff) :
		getEngine()->drawForegroundRectangle(drawX, drawY, drawFinalX, drawFinalY, this->colour);

	getEngine()->drawForegroundRectangle(drawX + BUTTON_OFFSET, drawY + BUTTON_OFFSET, 
		drawFinalX - BUTTON_OFFSET, drawFinalY - BUTTON_OFFSET, 0x000000);
	getEngine()->drawForegroundString(m_iCurrentScreenX-offsetX, m_iCurrentScreenY-offsetY, text.c_str(), 0xffffff, getEngine()->getFont("Cornerstone Regular.ttf", 40));
}

bool Button::isValidClick(int iX, int iY)
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

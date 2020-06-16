#include "controller.h"
#include "Scyyc1Engine.h"

constexpr auto CIRCLE_OFFSET = 3;

constexpr auto TRIANGLE_OFFSET = 5;
constexpr auto TRIANGLE_EDGE = 15;

controller::controller(BaseEngine* pEngine, 
	int xStart, int yStart, int index, 
	int iWidth, int iHeight, bool useTopLeftFor00, 
	int controlKey, string fruit)
	: DisplayableObject(xStart, yStart, pEngine, iWidth, iHeight, useTopLeftFor00)
{
	this->state = false;
	this->controlKey = controlKey;
	string buff = "./images/" + fruit + ".png";
	image = ImageManager::get()->getImagebyURL(buff, true, true);
	getEngine()->lockBackgroundForDrawing();
	image.renderImage(getEngine()->getBackgroundSurface(),
		0, 0, xStart + OVAL_OFFSET, yStart + OVAL_OFFSET,
		image.getWidth(), image.getHeight());
	getEngine()->unlockBackgroundForDrawing();
}

controller::~controller()
{
}


void controller::virtDraw()
{
	int drawX = m_iCurrentScreenX + CIRCLE_OFFSET;
	int drawY = m_iCurrentScreenY + CIRCLE_OFFSET;
	int drawNextX = m_iCurrentScreenX + m_iDrawWidth - CIRCLE_OFFSET - 1;
	int drawNextY = m_iCurrentScreenY + m_iDrawHeight - CIRCLE_OFFSET - 1;

	if (state)
	{
		image.renderImage(getEngine()->getForegroundSurface(),
			0, 0, drawX + OVAL_OFFSET, drawY + OVAL_OFFSET,
			image.getWidth(), image.getHeight());
	}

	// Draw triangles for the four corners
	int x_1 = m_iCurrentScreenX + TRIANGLE_OFFSET;
	int y_1 = m_iCurrentScreenY + TRIANGLE_OFFSET;
	getEngine()->drawForegroundTriangle(x_1, y_1, x_1, y_1 + TRIANGLE_EDGE, x_1 + TRIANGLE_EDGE, y_1, 0xff0000);

	int x_2 = m_iCurrentScreenX + getDrawWidth() - TRIANGLE_OFFSET;
	int y_2 = m_iCurrentScreenY + TRIANGLE_OFFSET;
	getEngine()->drawForegroundTriangle(x_2, y_2, x_2, y_2 + TRIANGLE_EDGE, x_2 - TRIANGLE_EDGE, y_2, 0xff0000);

	int x_3 = m_iCurrentScreenX + TRIANGLE_OFFSET;
	int y_3 = m_iCurrentScreenY + getDrawHeight() - TRIANGLE_OFFSET;
	getEngine()->drawForegroundTriangle(x_3, y_3, x_3, y_3 - TRIANGLE_EDGE, x_3 + TRIANGLE_EDGE, y_3, 0xff0000);

	int x_4 = m_iCurrentScreenX + getDrawWidth() - TRIANGLE_OFFSET;
	int y_4 = m_iCurrentScreenY + getDrawHeight() - TRIANGLE_OFFSET;
	getEngine()->drawForegroundTriangle(x_4, y_4, x_4, y_4 - TRIANGLE_EDGE, x_4 - TRIANGLE_EDGE, y_4, 0xff0000);
}


void controller::virtDoUpdate(int iCurrentTime)
{
	int drawX = m_iCurrentScreenX + CIRCLE_OFFSET;
	int drawY = m_iCurrentScreenY + CIRCLE_OFFSET;
	int drawNextX = m_iCurrentScreenX + m_iDrawWidth - CIRCLE_OFFSET - 1;
	int drawNextY = m_iCurrentScreenY + m_iDrawHeight - CIRCLE_OFFSET - 1;

	if (getEngine()->isKeyPressed(this->controlKey))
	{
		this->state = true;
	}

	redrawDisplay();
}

#pragma once
#include "header.h"
#include "DisplayableObject.h"

class speedController :
	public DisplayableObject
{
public:
	speedController(BaseEngine* pEngine, int xStart, int yStart, int iWidth, int iHeight, bool useTopLeftFor00);
	~speedController();
	void virtDraw();
	// Indicator of mouse click & drag events
	void switchIsDragged() { isDragged = !isDragged; };
	void switchIsClick() { isClick = !isClick; };
	void switchIsLocked() { isLocked = !isLocked; };
	bool getIsDragged() { return isDragged; };
	bool getIsClick() { return isClick; };
	bool getIsLocked() { return isLocked; };
	// Check if user click on right place
	bool isValidClick(int iX, int iY);
	// Function to change the speed controller's position according to user mouse drag
	void setPosition(int iX, int iY)
	{
		m_iCurrentScreenX = iX;
		m_iCurrentScreenY = iY;
	}

private:
	bool isDragged;				// Indicate that if the speed controller is dragged
	bool isClick;				// Indicate that if the speed controller is clicked
	bool isLocked;				// Indicate that if the speed controller is locked for changing
};


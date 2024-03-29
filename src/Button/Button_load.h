#pragma once
#include "Button.h"
class Button_load :
	public Button
{
public:
	Button_load(int xStart, int yStart, BaseEngine* pEngine,
		int iWidth, int iHeight, bool useTopLeftFor00,
		int colour, string text, int offsetX, int offsetY, int* stateId)
		:Button(xStart, yStart, pEngine,
			iWidth, iHeight, useTopLeftFor00,
			colour, text, offsetX, offsetY, stateId) {};
protected:
	void virtDoUpdate(int iCurrentTime);
};


#pragma once
#include "Button.h"
class Button_stop :
	public Button
{
public:
	Button_stop(int xStart, int yStart, BaseEngine* pEngine,
		int iWidth, int iHeight, bool useTopLeftFor00,
		int colour, string text, int offsetX, int offsetY, int* stateId, bool* isDraw)
		:Button(xStart, yStart, pEngine,
			iWidth, iHeight, useTopLeftFor00,
			colour, text, offsetX, offsetY, stateId) {
		this->isDraw = isDraw;
	};
protected:
	void virtDoUpdate(int iCurrentTime);
	bool* isDraw;
};


#pragma once
#include "../header.h"
#include "../DisplayableObject.h"
#include "../BaseEngine.h"
#include "../Configuration.h"
#include <string>
using namespace std;

class Button :
	public DisplayableObject
{
public:
	Button(int xStart, int yStart, BaseEngine* pEngine, 
		int iWidth, int iHeight, bool useTopLeftFor00, 
		int colour, string text, int offsetX, int offsetY, int* stateId)
		: DisplayableObject(xStart, yStart, pEngine, iWidth, iHeight, useTopLeftFor00) {
		this->colour = colour;
		this->text = text;
		this->isClick = false;
		this->isDragged = false;
		this->offsetX = offsetX;
		this->offsetY = offsetY;
		this->stateId = stateId;
	};

	void switchIsCLick() { isClick = !isClick; };
	void switchIsDragged() { isDragged = !isDragged; };
	bool isValidClick(int iX, int iY);
	bool getIsClick() { return isClick; };
	bool getIsDragged() { return isDragged; };

protected:
	virtual void virtDraw();
	virtual void virtDoUpdate(int iCurrentTime) {};
	int colour;
	string text;
	bool isClick;
	bool isDragged;
	int offsetX;
	int offsetY;
	int* stateId;
};
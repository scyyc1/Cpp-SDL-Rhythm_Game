#pragma once
#include "header.h"
#include "DisplayableObject.h"
#include "SimpleImage.h" 
using namespace std;

class controller :
	public DisplayableObject
{
public:
	controller(BaseEngine* pEngine, int xStart, int yStart, int index, int iWidth, int iHeight, bool useTopLeftFor00, int controlKey, string fruit);
	~controller();
	void virtDraw();
	void virtDoUpdate(int iCurrentTime);
	// Switch the state of the controller is the key is pressed or released
	void switchState() { state = !state; };

private:
	bool state;				// Indicate whether the key is pressed or not
	int controlKey;			// Indicate which key is pressed
	SimpleImage image;
	SimpleImage image_pressed;
};


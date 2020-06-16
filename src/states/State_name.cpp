#include "State_name.h"

void State_name::virtSetupBackgroundBuffer()
{
	engine->fillBackground(0x000000);
}

int State_name::virtInitialiseObjects()
{
	engine->drawableObjectsChanged();
	engine->destroyOldObjects(true);

	Button* start = new Button_back(650, 500, engine, 400, 75, false, 0xff0000, "confirm!", 85, 20, this->stateId);
	bs.push_back(start);
	engine->appendObjectToArray(start);
	engine->setAllObjectsVisible(true);
	return 0;
}

void State_name::virtDrawStringsOnTop()
{
	engine->drawForegroundString(50, 60, "Please enter your name: ",
		0xffffff, engine->getFont("Cornerstone Regular.ttf", 50));
	engine->drawForegroundString(50, 110, "(numbers and character, 10 letter max)",
		0xffffff, engine->getFont("Cornerstone Regular.ttf", 30));
	if (input.size() != 0) {
		char* temp = (char*)input.c_str();
		engine->drawForegroundString(350, 300, temp,
			0xffffff, engine->getFont("Cornerstone Regular.ttf", 50));
	}
	
}

void State_name::virtKeyDown(int iKeyCode)
{
	bool isNumber = (iKeyCode >= 48 && iKeyCode <= 57);
	bool isCapital = (iKeyCode >= 65 && iKeyCode <= 90);
	bool isLittle = (iKeyCode >= 97 && iKeyCode <= 122);
	bool isMax = (input.size() < 10);
	if ((isNumber || isCapital || isLittle)&&isMax) {
		char c = (char)iKeyCode;
		input += c;
	}
	
	if(iKeyCode==SDLK_BACKSPACE&&!input.empty())
		input.pop_back();
	PLAYER_NAME = input;
}


#include "State_pause.h"

void State_pause::virtSetupBackgroundBuffer()
{
	engine->fillBackground(0x000000);
}

int State_pause::virtInitialiseObjects()
{
	engine->drawableObjectsChanged();
	engine->destroyOldObjects(true);
	Button* continueGame = new Button_load(650, 350, engine, 400, 75, false, 0x2196F3, "Continue", 100, 20, this->stateId);
	Button* exit = new Button_exit(650, 500, engine, 400, 75, false, 0x2196F3, "Save & Exit", 150, 20, this->stateId);
	bs.push_back(continueGame);
	bs.push_back(exit);
	engine->appendObjectToArray(continueGame);
	engine->appendObjectToArray(exit);
	engine->setAllObjectsVisible(true);
	return 0;
}
#include "State_start.h"

void State_start::virtSetupBackgroundBuffer()
{
	engine->fillBackground(0x000000);

	for (int iX = 0; iX < engine->getWindowWidth(); iX++)
		for (int iY = 0; iY < engine->getWindowHeight(); iY++)
			if (rand() % 701 > 699) {
				engine->lockBackgroundForDrawing();
				engine->drawBackgroundOval(iX, iY, iX + rand() % 7, iY + rand() % 7, 0xffffff);
				engine->unlockBackgroundForDrawing();
			}
}

int State_start::virtInitialiseObjects()
{
	engine->drawableObjectsChanged();
	engine->destroyOldObjects(true);

	Button* start = new Button_start(650, 300, engine, 400, 75, false, 0x2196F3, "start", 70, 20, this->stateId);
	Button* load = new Button_load(650, 400, engine, 400, 75, false, 0x2196F3, "load", 68, 20, this->stateId);
	Button* rank = new Button_rank(650, 500, engine, 400, 75, false, 0x2196F3, "rank", 55, 20, this->stateId);
	Button* exit = new Button_exit(650, 600, engine, 400, 75, false, 0x2196F3, "exit", 55, 20, this->stateId);
	
	engine->appendObjectToArray(start);
	engine->appendObjectToArray(load);
	engine->appendObjectToArray(rank);
	engine->appendObjectToArray(exit);
	bs.push_back(start);
	bs.push_back(load);
	bs.push_back(rank);
	bs.push_back(exit);

	engine->setAllObjectsVisible(true);
	return 0;
}

void State_start::copyAllBackgroundBuffer()
{
	//std::random_shuffle(fallSpeed.begin(),fallSpeed.end());
	for (int i = 0; i < engine->getWindowWidth(); i++) {
		engine->getForegroundSurface()->copyRectangleFrom(engine->getBackgroundSurface(),
			i, 0, 1, engine->getWindowHeight(), 0, -(offset[i]));

		engine->getForegroundSurface()->copyRectangleFrom(engine->getBackgroundSurface(),
			i, (offset[i]) - engine->getWindowHeight(), 1, engine->getWindowHeight(),
			0, engine->getWindowHeight() - (offset[i]));
	}

}

void State_start::virtMainLoopDoBeforeUpdate()
{
	for (int i = 0; i < WINDOW_X; i++) {
		offset[i] = (fallSpeed[i] + offset[i]) % engine->getWindowHeight();
	}
	engine->redrawDisplay();
}

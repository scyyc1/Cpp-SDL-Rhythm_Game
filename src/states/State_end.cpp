#include "State_end.h"


void State_end::virtSetupBackgroundBuffer()
{
	engine->fillBackground(0x000000);

	for (int i = 0; i < box.getMapWidth(); i++)
			box.setMapValue(i, 0, i);
	box.setTopLeftPositionOnScreen(350, 200);
	box.drawAllTiles(engine, engine->getBackgroundSurface());
}

int State_end::virtInitialiseObjects()
{
	engine->drawableObjectsChanged();
	engine->destroyOldObjects(true);

	l = new MappableImageObject(shifter, 80, -100, engine, "./images/long.png", false);
	l->setTransparencyColour(l->getPixelColour(0, 0));
	ro = new MappableImageObject(rotator, 250, 300, engine, "./images/b_kiwi.png", false);
	ro->setTransparencyColour(l->getPixelColour(0, 0));

	Button* stop = new Button_stop(650, 500, engine, 400, 75, false, 0xff0000, "stop!", 57, 20, this->stateId, &isDraw);
	Button* back= new Button_back(650, 600, engine, 400, 75, false, 0x2196F3, "back", 55, 20, this->stateId);

	bs.push_back(back);
	bs.push_back(stop);
	engine->appendObjectToArray(back);
	engine->appendObjectToArray(stop);
	//engine->appendObjectToArray(l);
	engine->appendObjectToArray(ro);
	engine->setAllObjectsVisible(true);
	return 0;
}

void State_end::virtDrawStringsUnderneath()
{
}

void State_end::virtDrawStringsOnTop()
{
	char buf[128];
	sprintf(buf, "Your final score is: %d", finalScore);
	engine->drawForegroundString(80, 50, buf, 0xffffff, engine->getFont("Cornerstone Regular.ttf", 80));
}

void State_end::virtMainLoopDoBeforeUpdate()
{
	int iOffset = engine->getModifiedTime() / 10;
	shifter->setYShift((double)iOffset / 2.0);
	rotator->setRotation((double)iOffset / -100.0);
	engine->redrawDisplay();

	if (engine->getRawTime() > alignTime && !isDraw) {
		for (int i = 0; i < box.getMapWidth(); i++)
			box.setAndRedrawMapValueAt(i, 0,
				(box.getMapValue(i, 0) + 1) % 5,
				engine, engine->getBackgroundSurface());

		alignTime += next;
		engine->redrawDisplay();
	}
}

void State_end::virtMainLoopDoAfterUpdate()
{
	if (*this->stateId == 1) {
		r->addToRank(PLAYER_NAME, finalScore);
		r->save();
	}
	
	if (isDraw && CHANCE>0) {
		int r1 = rand() % 4 + 5;
		int r2 = rand() % 4 + 5;
		int r3 = rand() % 4 + 5;

		int level = (r1==r2) + (r1==r3) + (r2==r3);
		switch (level) {
		case 0:finalScore += 10; break;
		case 1:finalScore += 50; break;
		case 3:finalScore += 100; break;
		}
		box.setAndRedrawMapValueAt(0, 0, r1,
			engine, engine->getBackgroundSurface());
		box.setAndRedrawMapValueAt(1, 0, r2,
			engine, engine->getBackgroundSurface());
		box.setAndRedrawMapValueAt(2, 0, r3,
			engine, engine->getBackgroundSurface());
		CHANCE--;
	}
}


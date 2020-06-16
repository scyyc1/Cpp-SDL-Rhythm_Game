#include "State_rank.h"

void State_rank::virtSetupBackgroundBuffer()
{
	engine->fillBackground(0x000000);
}

int State_rank::virtInitialiseObjects()
{
	engine->drawableObjectsChanged();
	engine->destroyOldObjects(true);

	Button* start = new Button_back(650, 600, engine, 400, 75, false, 0xff0000, "back", 55, 20, this->stateId);
	bs.push_back(start);
	engine->appendObjectToArray(start);
	engine->setAllObjectsVisible(true);
	return 0;
}

void State_rank::virtDrawStringsOnTop()
{
	engine->drawForegroundString(550, 25, "Ranking", 0xff0000,
		engine->getFont("Cornerstone Regular.ttf", 75));
	for (int i = 0; i < r->size; i++) {
		char buf[128];
		int temp = r->score[i];
		sprintf(buf, "NO.%d:", i+1);
		engine->drawForegroundString(150, (i + 1) * RANK_LINE_SPACE, buf, 0xffffff, 
			engine->getFont("Cornerstone Regular.ttf", 50));
		engine->drawForegroundString(350, (i + 1) * RANK_LINE_SPACE, r->name[i].c_str(), 0xffffff,
			engine->getFont("Cornerstone Regular.ttf", 50));
		sprintf(buf, "%d", r->score[i]);
		engine->drawForegroundString(700, (i + 1) * RANK_LINE_SPACE, buf, 0xffffff,
			engine->getFont("Cornerstone Regular.ttf", 50));
	}
}

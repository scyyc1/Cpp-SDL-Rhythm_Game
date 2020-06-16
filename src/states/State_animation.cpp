#include "State_animation.h"

void State_animation::virtSetupBackgroundBuffer()
{
	engine->fillBackground(0x000000);
}

void State_animation::virtMainLoopDoBeforeUpdate() 
{
	while (frame >= 0&& engine->getRawTime()>time) {
		int colour = RED * frame + GREEN * frame + BLUE * frame;
		colour = (RED * frame + GREEN * frame + BLUE * frame)*5;
		engine->fillBackground(colour);
		direction ? frame++ : frame--;
		if (frame == 51)
			direction = !direction;
		engine->redrawDisplay();
		time=engine->getRawTime()+80;
	}
}

void State_animation::virtMainLoopDoAfterUpdate()
{
	if (frame == 0)
		*stateId = 6;
}

void State_animation::virtDrawStringsOnTop()
{
	engine->drawForegroundString(300, 200, "Yutian Chen's", 0x000000, engine->getFont("Cornerstone Regular.ttf", 100));
	engine->drawForegroundString(300, 350, "Coursework", 0x000000, engine->getFont("Cornerstone Regular.ttf", 100));
}



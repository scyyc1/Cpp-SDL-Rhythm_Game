#include "State_gaming.h"

State_gaming::~State_gaming()
{
}

void State_gaming::virtSetupBackgroundBuffer()
{
	engine->fillBackground(0x000000);

	// Draw the background framework
	engine->getBackgroundSurface()->mySDLLockSurface();
	engine->drawBackgroundLine(0, 200, 1300, 200, 0xffffff);
	engine->drawBackgroundLine(0, 300, 1300, 300, 0xffffff);
	engine->drawBackgroundLine(0, 400, 1300, 400, 0xffffff);
	engine->drawBackgroundLine(0, 500, 1300, 500, 0xffffff);
	engine->drawBackgroundLine(0, 600, 1300, 600, 0xffffff);
	engine->drawBackgroundLine(1200, 200, 1200, 600, 0xffffff);
	engine->getBackgroundSurface()->mySDLUnlockSurface();

	// Initialize the tileManager representing the "life" element
	for (int i = 0; i < MAP_WIDTH; i++)
		for (int j = 0; j < MAP_HEIGHT; j++)
			life.setMapValue(i, j, 1);
	life.setTopLeftPositionOnScreen(LIFEMAP_START_X, LIFEMAP_START_Y);
	life.drawAllTiles(engine, engine->getBackgroundSurface());

	// Initialize the tileManager representing the four tracks
	for (int i = 0; i < AVENUE_MAP_WIDTH; i++)
		for (int j = 0; j < AVENUE_MAP_HEIGHT; j++)
			avenue.setMapValue(i, j, rand());
	avenue.setTopLeftPositionOnScreen(AVENUE_START_X, AVENUE_START_Y);
	avenue.drawAllTiles(engine, engine->getBackgroundSurface());

	// Draw the dialog box
	engine->getBackgroundSurface()->mySDLLockSurface();
	engine->drawBackgroundLine(120, 640, 120, 720, 0xffffff);
	engine->drawBackgroundLine(120, 640, 140, 620, 0xffffff);
	engine->drawBackgroundLine(120, 720, 140, 740, 0xffffff);

	engine->drawBackgroundLine(140, 620, 340, 620, 0xffffff);
	engine->drawBackgroundLine(170, 740, 340, 740, 0xffffff);

	engine->drawBackgroundLine(340, 620, 360, 640, 0xffffff);
	engine->drawBackgroundLine(360, 640, 360, 720, 0xffffff);
	engine->drawBackgroundLine(360, 720, 340, 740, 0xffffff);

	engine->drawBackgroundLine(120, 780, 140, 740, 0xffffff);
	engine->drawBackgroundLine(120, 780, 170, 740, 0xffffff);
	engine->getBackgroundSurface()->mySDLUnlockSurface();

	// Draw the speed controlling bar
	engine->getBackgroundSurface()->mySDLLockSurface();
	engine->drawBackgroundLine(MIN_POS_X, MIN_POS_Y, MAX_POS_X, MIN_POS_Y, 0xffffff);
	engine->getBackgroundSurface()->mySDLUnlockSurface();

	SimpleImage image = ImageManager::get()->getImagebyURL("./images/cherry.png", true, true);
	int w = image.getWidth();
	int h = image.getHeight();
	image.renderImage(engine->getBackgroundSurface(), 0, 0, 0, 0, w, h);

	nativeInitialization();
}

int State_gaming::virtInitialiseObjects()
{
	engine->drawableObjectsChanged();
	engine->destroyOldObjects(true);

	// Initialize controllers
	controller* c1 = new controller(engine, CONTROLLER_START_X, CONTROLLER_START_1_Y, 0, CONTROLLER_SIZE, CONTROLLER_SIZE, true, SDLK_UP, "cherry");
	controller* c2 = new controller(engine, CONTROLLER_START_X, CONTROLLER_START_2_Y, 0, CONTROLLER_SIZE, CONTROLLER_SIZE, true, SDLK_DOWN, "kiwi");
	controller* c3 = new controller(engine, CONTROLLER_START_X, CONTROLLER_START_3_Y, 0, CONTROLLER_SIZE, CONTROLLER_SIZE, true, SDLK_LEFT, "watermelon");
	controller* c4 = new controller(engine, CONTROLLER_START_X, CONTROLLER_START_4_Y, 0, CONTROLLER_SIZE, CONTROLLER_SIZE, true, SDLK_RIGHT, "lemon");

	this->controllerSet.push_back(c1);
	this->controllerSet.push_back(c2);
	this->controllerSet.push_back(c3);
	this->controllerSet.push_back(c4);

	// Initialize sample notes

	note::setSpeed(4.0);				// The speed of notes are initialze to be 1.1

	// Initialize speed controller
	speedController* s = new speedController(engine, MIN_POS_X, MIN_POS_Y, CONTROLLER_SIZE / 2, CONTROLLER_SIZE / 2, false);
	this->sc = s;

	// Store all elements to the object array
	engine->appendObjectToArray(c1);
	engine->appendObjectToArray(c2);
	engine->appendObjectToArray(c3);
	engine->appendObjectToArray(c4);

	engine->appendObjectToArray(s);
	engine->appendObjectToArray(NULL);
	//engine->appendObjectToArray(n5);

	engine->setAllObjectsVisible(true);
	return 0;
}

void State_gaming::virtDrawStringsOnTop()
{
	engine->getForegroundSurface()->mySDLLockSurface();
	switch (evalutaion)
	{
	case 0:
		engine->drawForegroundString(140, 660, "Perfect!", 0xffffff, engine->getFont("Cornerstone Regular.ttf", 40));
		break;
	case 1:
		engine->drawForegroundString(140, 660, "Great!", 0xffffff, engine->getFont("Cornerstone Regular.ttf", 40));
		break;
	case 2:
		engine->drawForegroundString(140, 660, "Good!", 0xffffff, engine->getFont("Cornerstone Regular.ttf", 40));
		break;
	case 3:
		engine->drawForegroundString(140, 660, "Bad!", 0xffffff, engine->getFont("Cornerstone Regular.ttf", 40));
		break;
	case 4:
		engine->drawForegroundString(140, 660, "Miss!", 0xffffff, engine->getFont("Cornerstone Regular.ttf", 40));
		break;
	}

	// Consider & slightly copy from tutorial demo
	char buf[128];
	sprintf(buf, "Your point is: %d", point);
	engine->drawForegroundString(150, 60, buf, 0xffffff, engine->getFont("Cornerstone Regular.ttf", 50));

	char temp[128];
	sprintf(temp, ":%d", point);
	if (getObstacle())
	{
		engine->drawForegroundString(50, CONTROLLER_START_1_Y, temp, 0xffffff, engine->getFont("Cornerstone Regular.ttf", 400));
	}
	engine->getForegroundSurface()->mySDLUnlockSurface();
}

void State_gaming::virtDrawStringsUnderneath()
{
	engine->getBackgroundSurface()->mySDLLockSurface();
	engine->drawBackgroundString(150, 10, "Rhythm Master", 0xffffff, engine->getFont("Cornerstone Regular.ttf", 48));
	engine->drawBackgroundString(430, 650, "Speed Controller:", 0xffffff, engine->getFont("Cornerstone Regular.ttf", 40));
	engine->drawBackgroundString(700, 50, "Life:", 0xffffff, engine->getFont("Cornerstone Regular.ttf", 40));

	engine->drawBackgroundString(500, CONTROLLER_START_1_Y, "Track 1", 0xffffff, engine->getFont("Cornerstone Regular.ttf", 40));
	engine->drawBackgroundString(500, CONTROLLER_START_2_Y, "Track 2", 0xffffff, engine->getFont("Cornerstone Regular.ttf", 40));
	engine->drawBackgroundString(500, CONTROLLER_START_3_Y, "Track 3", 0xffffff, engine->getFont("Cornerstone Regular.ttf", 40));
	engine->drawBackgroundString(500, CONTROLLER_START_4_Y, "Track 4", 0xffffff, engine->getFont("Cornerstone Regular.ttf", 40));
	engine->getBackgroundSurface()->mySDLUnlockSurface();
}

// When releasing a key, the controller 
void State_gaming::virtKeyUp(int iKeyCode)
{
	switch (iKeyCode)
	{
	case SDLK_UP:
		controllerSet[0]->switchState();
		break;
	case SDLK_DOWN:
		controllerSet[1]->switchState();
		break;
	case SDLK_LEFT:
		controllerSet[2]->switchState();
		break;
	case SDLK_RIGHT:
		controllerSet[3]->switchState();
		break;
	}
}

void State_gaming::virtKeyDown(int iKeyCode)
{
 	DisplayableObject* n;
	switch (iKeyCode)
	{
	case SDLK_UP:catchInput(0);break;
	case SDLK_DOWN:catchInput(1); break;
	case SDLK_LEFT:catchInput(2); break;
	case SDLK_RIGHT:catchInput(3); break;
	}

	int id = note_id - (Tracks[0].size() + Tracks[1].size() + Tracks[2].size() + Tracks[3].size());
	if (id < 0)id = 0;
	switch (iKeyCode)
	{
	case ' ':
		sc->switchIsLocked();
		break;
	case 'g':
		note::setSpeed(1.0);
		break;
	case 'o':
		note::setSpeed(0);
		break;
	case 'c':
		avenue.changeColour();
		break;
		//End
	case 's':
		*this->stateId = 5;
		script->saveScript(id);
		break;
	case SDLK_ESCAPE:
		engine->setExitWithCode(0);
		break;
	}
}

void State_gaming::virtMouseDown(int iButton, int iX, int iY)
{
	if (iButton == SDL_BUTTON_LEFT)
	{
		if (sc->isValidClick(iX, iY))
		{
			sc->switchIsDragged();
			sc->switchIsClick();
		}	
	}
}


void State_gaming::virtMouseUp(int iButton, int iX, int iY)
{
	if (iButton == SDL_BUTTON_LEFT)
	{
		if (sc->getIsClick())
		{
			sc->switchIsDragged();
			sc->switchIsClick();
		}
	}
}

void State_gaming::virtMouseMoved(int iX, int iY)
{
	if (sc->getIsDragged())
	{
		if (sc->isValidClick(iX, iY) && sc->getIsLocked())
		{
			if (iX >= MIN_POS_X && iX <= MAX_POS_X)
			{
				sc->setPosition(iX, sc->getYCentre());
				double speed = ((double)iX - (double)MIN_POS_X) / (double)40;
				note::setSpeed(speed);
			}
		}
	}
}

void State_gaming::virtMainLoopDoBeforeUpdate()
{
	if (engine->getRawTime() > alignTime &&!noteScript.empty()) {
			int time = engine->getRawTime();
			alignTime = time;
			if (note_id+1!=script->size) {
				alignTime += script->Appear[note_id] * BEATS;
			}
			switch (script->Type[note_id]) {
			case 0:
				Tracks[script->track[note_id]].push(noteScript.front()); 
				engine->appendObjectToArray(noteScript.front());
				break;
			case 1:
				Tracks[script->track[note_id]].push(noteScript.front()->getThisNote());
				engine->appendObjectToArray(noteScript.front()->getThisNote());
				Tracks[noteScript.front()->getAnother()->getTrack()].push(noteScript.front()->getAnother());
				engine->appendObjectToArray(noteScript.front()->getAnother());
				break;
			case 2:
				Tracks[script->track[note_id]].push(noteScript.front()); 
				engine->appendObjectToArray(noteScript.front()); 
				break;
			}
			noteScript.pop();
			note_id++;
	}
}

void State_gaming::virtMainLoopDoAfterUpdate()
{
	checkMiss(0);
	checkMiss(1);
	checkMiss(2);
	checkMiss(3);

	if (Tracks[0].empty()&& Tracks[1].empty() && Tracks[2].empty() && Tracks[3].empty()&&noteScript.empty()) {
		*stateId = 4;
		finalScore = point;
	}
}

void State_gaming::nativeInitialization()
{
	this->point = 0;
	this->evalutaion = -1;
	this->sc = NULL;
	this->obstacle = false;
	this->nextBeat = BEATS;
	this->noteScript = script->getScriptStream();
	this->alignTime = 0;
	this->note_id = 0;
}

void State_gaming::checkMiss(int trakID)
{
	note* n;
	if (!Tracks[trakID].empty()) {
		n = Tracks[trakID].front();
		if (n->getDrawingRegionRight() > engine->getWindowWidth() + 10) {
			evalutaion = MISS;
			missPunishment();
			Tracks[trakID].pop();
			engine->removeDisplayableObject(n);
		}
	}
}

void State_gaming::catchInput(int trackID) 
{
	DisplayableObject* n;
	if (!Tracks[trackID].empty()) {
		Mix_PlayChannel(-1, soundEffect[trackID], 0);
		n = Tracks[trackID].front();
		Tracks[trackID].pop();
		EvaluationDetermination(n->getDrawingRegionLeft(), controllerSet[trackID]->getDrawingRegionLeft());
		engine->removeDisplayableObject(n);
	}
}

void State_gaming::EvaluationDetermination(int noteX, int controllerX)
{
	if (controllerX - noteX <= 20)
	{
		evalutaion = PERFECT;
		point += 100;
	}
	else if (controllerX - noteX <= 40)
	{
		evalutaion = GREAT;
		point += 60;
	}
	else if (controllerX - noteX <= 60)
	{
		evalutaion = GOOD;
		point += 30;
	}
	else if (controllerX - noteX <= 80)
	{
		evalutaion = BAD;
		point += 10;
	}
	else
	{
		evalutaion = MISS;
		missPunishment();
	}
}

void State_gaming::missPunishment()
{
	life.setAndRedrawMapValueAt(life.getLifeX(), life.getLifeY(), 0, engine, engine->getBackgroundSurface());
	life.costLife();

	if (life.getLife() == 0) {
		*stateId = 4;
		CHANCE = 1;
		finalScore = point;
	}

	engine->redrawDisplay();
}
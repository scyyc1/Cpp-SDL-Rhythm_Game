#pragma once
#include "State.h"
#include "../Button/Button.h"
#include "../Button/Button_exit.h"
#include "../Button/Button_load.h"
#include "../Button/Button_back.h"
#include "../Button/Button_start.h"
#include "../DrawingFilters.h"
#include "../DrawingFilters.h"
class State_function :
	public State
{
public:
	State_function(string name, BaseEngine* engine, int& stateId) 
		: State(name, engine, stateId)
	{};
	~State_function() {};

	// Initialization
	virtual void virtSetupBackgroundBuffer() {};
	virtual int virtInitialiseObjects() { return 0; };
	// Text related
	virtual void virtDrawStringsUnderneath() {};
	virtual void virtDrawStringsOnTop() {};
	// Keyboard input
	virtual void virtKeyUp(int iKeyCode) {};
	virtual void virtMouseDown(int iButton, int iX, int iY) {
		if (iButton == SDL_BUTTON_LEFT)
		{
			for (int i = 0; i < bs.size(); i++)
			{
				if (bs[i]->isValidClick(iX, iY)) {
					bs[i]->switchIsCLick();
					bs[i]->switchIsDragged();
					engine->redrawDisplay();
				}
			}
		}
	};
	virtual void virtMouseUp(int iButton, int iX, int iY) {
		if (iButton == SDL_BUTTON_LEFT)
		{
			for (int i = 0; i < bs.size(); i++)
			{
				if (bs[i]->getIsClick()) {
					bs[i]->switchIsCLick();
					bs[i]->switchIsDragged();
					engine->redrawDisplay();
				}
			}
		}
	};
	virtual void virtMouseMoved(int iX, int iY) {};
	// Update related
	virtual void virtMainLoopDoBeforeUpdate() {};
	virtual void virtMainLoopDoAfterUpdate() {};
	virtual void virtMainLoopPreUpdate() {};
	virtual void virtMainLoopPostUpdate() {};
	virtual void virtMainLoopStartIteration() {};
	virtual void copyAllBackgroundBuffer() {
		engine->getForegroundSurface()->copyEntireSurface(engine->getBackgroundSurface());
	};
protected:
	vector<Button*> bs;
};


#pragma once
#include "State.h"
#include "../Configuration.h"
#include "../DrawingSurface.h"
class State_animation :
	public State
{
public:
	State_animation(string name, BaseEngine* engine, int& id)
		: State(name, engine, id)
	{
		this->frame = 0;
		this->direction = true;
		this->time = 0;
	}

private:
	void virtSetupBackgroundBuffer();
	void virtMainLoopDoBeforeUpdate();
	void virtMainLoopDoAfterUpdate();
	void virtDrawStringsOnTop();
	int frame;
	bool direction;
	int time;		// Time for 
};


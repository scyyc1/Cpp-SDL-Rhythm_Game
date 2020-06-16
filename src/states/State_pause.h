#pragma once
#include "State.h"
#include "State_function.h"
#include "../Button/Button_start.h"
#include "../Button/Button_exit.h"
#include "../Button/Button_load.h"
using namespace std;
class State_pause :
	public State_function
{
public:
	State_pause(string name, BaseEngine* engine, int& id)
		: State_function(name, engine, id) {
	}

protected:
	void virtSetupBackgroundBuffer();
	int virtInitialiseObjects();
};


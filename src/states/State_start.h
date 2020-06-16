#pragma once
#include "State.h"
#include "State_function.h"
#include "../Button/Button.h"
#include "../Button/Button_start.h"
#include "../Button/Button_exit.h"
#include "../Button/Button_load.h"
#include "../Button/Button_rank.h"
#include "../Configuration.h"
class State_start :
	public State_function
{
public:
	State_start(string name, BaseEngine* engine, int& id)
		: State_function(name, engine, id) {
		for (int i = 0; i < WINDOW_X; i++) {
			this->fallSpeed.push_back(rand() % 5 + 1);
			this->offset.push_back(0);
		}
	}

	// Initialization
	void virtSetupBackgroundBuffer();
	int virtInitialiseObjects();
	void copyAllBackgroundBuffer();
	// Loop related
	void virtMainLoopDoBeforeUpdate();

private:
	vector<int> fallSpeed;
	vector<int> offset;
};


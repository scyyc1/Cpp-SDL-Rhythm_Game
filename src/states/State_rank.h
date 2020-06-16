#pragma once
#include "State_function.h"
#include "../Ranking/Ranking.h"
#include "../Configuration.h"
class State_rank :
	public State_function
{
public:
	State_rank(string name, BaseEngine* engine, int& id)
		: State_function(name, engine, id) {
		this->r = new Ranking();
	};
protected:
	void virtSetupBackgroundBuffer();
	int virtInitialiseObjects();
	void virtDrawStringsOnTop();

private:
	Ranking* r;
};


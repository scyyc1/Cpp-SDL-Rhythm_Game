#pragma once
#include "State_function.h"
#include "../Configuration.h"
#include "../Ranking/Ranking.h"
using namespace std;
class State_name :
	public State_function
{
public:
	State_name(string name, BaseEngine* engine, int& id)
		: State_function(name, engine, id) {
	};
protected:
	void virtSetupBackgroundBuffer();
	int virtInitialiseObjects();
	void virtDrawStringsOnTop();
	void virtKeyDown(int iKeyCode);
private:
	string input;
};


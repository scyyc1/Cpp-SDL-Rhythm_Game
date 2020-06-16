#pragma once
#include "..\header.h"
#include "..\BaseEngine.h"
using namespace std;

class State {
protected:
	string name;
	BaseEngine* engine;
	void setName(string s) { this->name = s; };

public:
	State(string name, BaseEngine* engine, int& stateId) {
		this->name = name;
		this->engine = engine;
		this->stateId = &stateId;
	}
	~State() {}

	// Initialization
	virtual void virtInitialise() {};
	virtual void virtSetupBackgroundBuffer() {};
	virtual int virtInitialiseObjects() { return 0; };
	// Text related
	virtual void virtDrawStringsUnderneath() {};
	virtual void virtDrawStringsOnTop() {};
	// Keyboard input
	virtual void virtKeyUp(int iKeyCode) {};
	virtual void virtKeyDown(int iKeyCode) {};
	// Mouse input(all speed controller related)
	virtual void virtMouseDown(int iButton, int iX, int iY) {};
	virtual void virtMouseUp(int iButton, int iX, int iY) {};
	virtual void virtMouseMoved(int iX, int iY) {};
	virtual void virtMouseWheel(int x, int y, int which, int timestamp) {};
	// Update related
	virtual void virtMainLoopDoBeforeUpdate() {};
	virtual void virtMainLoopDoAfterUpdate() {};
	virtual void virtMainLoopPreUpdate() {};
	virtual void virtMainLoopPostUpdate() {};
	virtual void virtMainLoopStartIteration() {};

	virtual void copyAllBackgroundBuffer() {
		engine->getForegroundSurface()->copyEntireSurface(engine->getBackgroundSurface());
	};

	BaseEngine* getEngine() { return engine; };
protected:
	int* stateId;
};

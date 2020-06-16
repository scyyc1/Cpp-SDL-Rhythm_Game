#pragma once
#include "header.h"
#include "BaseEngine.h"
#include "states\State.h"
#include "states\State_gaming.h"
#include "states\State_start.h"
#include "states\State_animation.h"
#include "states\State_end.h"
#include "states\State_pause.h"
#include "states/State_name.h"
#include "states/State_rank.h"

using namespace std;

class Scyyc1Engine :
	public BaseEngine, public CoordinateMapping
{
public:
	Scyyc1Engine() : Scaling(0, 0, this), Translation(0, 0, &Scaling)
	{
		rotator = new CoordinateMappingRotate(0.0);
		shifter = new CoordinateMappingShiftXY(0, 0);
		//this->s = new State_gaming("gaming", this);
		this->stateNum = 0;
		this->currentState = 0;
		State* animation = new State_animation("animation", this, this->currentState);
		State* start = new State_start("start", this, this->currentState);
		State* gaming = new State_gaming("gaming", this, this->currentState);
		State* load = new State_gaming("oldgame", this, this->currentState);
		State* end = new State_end("end", this, this->currentState, shifter, rotator);
		State* pause = new State_pause("pause", this, this->currentState);
		State* name = new State_name("name", this, this->currentState);
		State* rank = new State_rank("rank", this, this->currentState);

		this->stateList.push_back(animation);
		this->stateList.push_back(start);
		this->stateList.push_back(gaming);
		this->stateList.push_back(load);
		this->stateList.push_back(end);
		this->stateList.push_back(pause);
		this->stateList.push_back(name);
		this->stateList.push_back(rank);
		this->s = stateList[0];
	};
	~Scyyc1Engine() {};
	// Initialize background & objects
	int virtInitialise() override;
	void virtSetupBackgroundBuffer();
	int virtInitialiseObjects();
	// Text related
	void virtDrawStringsUnderneath();
	void virtDrawStringsOnTop();
	// Keyboard input
	void virtKeyUp(int iKeyCode);
	void virtKeyDown(int iKeyCode);
	// Mouse input(all speed controller related)
	void virtMouseDown(int iButton, int iX, int iY);
	void virtMouseUp(int iButton, int iX, int iY);
	void virtMouseMoved(int iX, int iY);
	virtual void virtMouseWheel(int x, int y, int which, int timestamp) {
		if (y < 0)
			Scaling.compress();
		else if (y > 0)
			Scaling.stretch();
		redrawDisplay();
	};
	// Update related
	void virtMainLoopDoBeforeUpdate();
	void virtMainLoopDoAfterUpdate();
	void virtMainLoopPreUpdate();
	void virtMainLoopPostUpdate();
	void virtMainLoopStartIteration();

	void copyAllBackgroundBuffer();
	bool mapCoordinates(double& x, double& y, const SimpleImage& image) override;
	bool checkRotateBorder(double& x, double& y, const SimpleImage& image);
	

	State* getState() { return s; };
	void switchState(int stateID) {
		delete this->s;
		switch (stateID) {
		case 0:stateList[stateID] = new State_animation("animation", this, this->currentState); break;
		case 1:stateList[stateID] = new State_start("start", this, this->currentState); break;
		case 2:stateList[stateID] = new State_gaming("gaming", this, this->currentState); break;
		case 3:stateList[stateID] = new State_gaming("oldgame", this, this->currentState); break;
		case 4:stateList[stateID] = new State_end("end", this, this->currentState, shifter, rotator); break;
		case 5:stateList[stateID] = new State_pause("pause", this, this->currentState); break;
		case 6:stateList[stateID] = new State_name("name", this, this->currentState); break;
		case 7:stateList[stateID] = new State_rank("rank", this, this->currentState); break;
		}
		this->s = stateList[stateID];
		virtInitialise();
	};
private:

	State* s;						// Working state currently
	int stateNum;
	int currentState;
	vector<State*> stateList;
	FilterPointsScaling Scaling;
	FilterPointsTranslation Translation;
	CoordinateMappingShiftXY* shifter;
	CoordinateMappingRotate* rotator;
};
#pragma once
#include "State.h"
#include "State_function.h"
#include "../Button/Button_back.h"
#include "../Button/Button_stop.h"
#include "../Configuration.h"
#include "../luckyDraw.h"
#include "../Ranking/Ranking.h"
#include "../DragableObject.h"
#include "../CoordinateMapping.h"
#include "../MappableImageObject.h"
class State_end :
	public State_function
{
public:
	State_end(string name, BaseEngine* engine, int& id, 
		CoordinateMappingShiftXY* shifter, CoordinateMappingRotate* rotator)
		: State_function(name, engine, id)
	{
		this->rotator = rotator;
		this->shifter = shifter;
		r = new Ranking();
		alignTime = 0;
		loop = 0;
		isDraw = false;
		CHANCE = 1;
	}

protected:
	void virtSetupBackgroundBuffer();
	int virtInitialiseObjects();
	void virtDrawStringsUnderneath();
	void virtDrawStringsOnTop();
	void virtMainLoopDoBeforeUpdate();
	void virtMainLoopDoAfterUpdate();

private:
	Ranking* r;
	luckyDraw box;
	bool isDraw;
	int loop;
	int next = 80;
	int alignTime;
	CoordinateMappingShiftXY* shifter;
	CoordinateMappingRotate* rotator;
	MappableImageObject* l;
	MappableImageObject* ro;
};


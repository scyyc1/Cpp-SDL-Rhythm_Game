#pragma once
#include "..\header.h"
#include "State.h"
#include "../Configuration.h"
#include "..\controller.h"
#include "..\lifeManager.h"
#include <string.h>
#include "..\speedController.h"
#include "..\Scyyc1TileManager.h"
#include <vector>
#include "..\Notes\note.h"
#include "..\notes\DoubleNote.h"
#include "..\notes\LongNote.h"
#include "..\BaseEngine.h"
#include <queue>
#include "../scripts/Script.h"
#include "SDL_mixer.h"

using namespace std;

class State_gaming : public State{

public:
	State_gaming(string name, BaseEngine* engine, int &id) 
		: State (name, engine, id) {

		this->script = (name._Equal("gaming")) ? (new Script("one", Tracks)) : (new Script("backup", Tracks));
		
		script->buildNoteSet(engine, &avenue);
		Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096);
		soundEffect.push_back(Mix_LoadWAV("./sounds/bmboledg.wav"));
		soundEffect.push_back(Mix_LoadWAV("./sounds/HH open.wav"));
		soundEffect.push_back(Mix_LoadWAV("./sounds/PlasticTray_PS.wav"));
		soundEffect.push_back(Mix_LoadWAV("./sounds/Side Stick_Kalavrezos_2011.wav"));
	
		for (int i = 0; i < CONTROLLER_NUM; i++) {
			queue<note*> temp;
			Tracks.push_back(temp);
		}
		cout << Tracks[0].size() << endl;
	}
	~State_gaming();

	// Initialization
	virtual void virtSetupBackgroundBuffer();
	virtual int virtInitialiseObjects();
	// Text related
	virtual void virtDrawStringsUnderneath();
	virtual void virtDrawStringsOnTop();
	// Keyboard input
	virtual void virtKeyUp(int iKeyCode);
	virtual void virtKeyDown(int iKeyCode);
	// Mouse input(all speed controller related)
	virtual void virtMouseDown(int iButton, int iX, int iY);
	virtual void virtMouseUp(int iButton, int iX, int iY);
	virtual void virtMouseMoved(int iX, int iY);
	// Update related
	virtual void virtMainLoopDoBeforeUpdate();
	virtual void virtMainLoopDoAfterUpdate();
	
	bool getObstacle() { return obstacle; };
	void switchObstacle() { this->obstacle = !this->obstacle; };
	TileManager getAvenue() { return avenue;};
	vector<queue<note*>> getTracks() { return Tracks; };

private:

	vector<controller*> controllerSet;		// Keep track of all (4 totally) controllers
	vector<queue<note*>> Tracks;
	Mix_Music* music;
	vector<Mix_Chunk*> soundEffect;
	queue<note*> noteScript;

	lifeManager life;							// The tile representing the life
	Scyyc1TileManager avenue;					// The tracks
	speedController* sc;
	int evalutaion;								// Evalutates the player's performance on each note 
	int point;									// Evalutates the player's performance overall
	bool obstacle;								// Indicator for visual obstacle
	int nextBeat = 0;
	int alignTime;
	int note_id;
	Script* script;

	// Evalutates the player's performance on each note 
	void EvaluationDetermination(int noteX, int controllerX);
	void checkMiss(int trakID);
	void catchInput(int trakID);
	void nativeInitialization();
	void missPunishment();
	bool isNextBeat() {
		int time = engine->getRawTime();
		if (time % BEATS == 0 || time > nextBeat) {
			nextBeat += BEATS;
			return true;
		}
		else {
			return false;
		}
	};
};


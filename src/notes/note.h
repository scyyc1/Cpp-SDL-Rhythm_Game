#pragma once
#include "../header.h"
#include "../DisplayableObject.h"
#include "../TileManager.h"
#include "../Configuration.h"
#include "../SimpleImage.h" 
using namespace std;

class note :
	public DisplayableObject
{
public:
	note(BaseEngine* pEngine, int xStart, int yStart, 
		int index, int iWidth, int iHeight, 
		bool useTopLeftFor00, int track, 
		TileManager* pTileManager);
	~note();
	virtual void virtDraw();
	virtual void virtDoUpdate(int iCurrentTime);

	virtual note* getThisNote() { return this; };
	virtual note* getAnother() { return NULL; };
	// Relocate the note to the head of the track
	void restart() { m_iCurrentScreenX = (int)startPosY; };
	// Modify the speed of all notes
	static void setSpeed(double newSpeed) { speed = newSpeed; };
	int getIndex() { return this->index; };
	int getTrack() { return track; };
	virtual note* selfCopy();

	 
protected:
	virtual void drawInitial(int X, int Y, int FX, int FY, int track);

	int track;							// Indicate which track the note is in
	static double speed;				// Shared speed
	double startPosX;					// Indicate the head of track
	double startPosY;					
	TileManager* m_pTileManager;		// Pointer to tileManager for track's "special effects"
	double moveX;						// Indicate the moving coordinate of the note
	double moveY;
	int index;
	SimpleImage image;
};


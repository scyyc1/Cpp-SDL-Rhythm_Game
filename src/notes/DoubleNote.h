#pragma once
#include "..\header.h"
#include "note.h"
#include "..\Configuration.h"
#include "..\BaseEngine.h"
#include <queue>
using namespace std;

class DoubleNote :
	public note {

public:
	DoubleNote(BaseEngine* pEngine,
		int xStart, int yStart, int index,
		int iWidth, int iHeight, bool useTopLeftFor00,
		int track, TileManager* pTileManager);
	~DoubleNote();

	virtual note* getThisNote() { return n1; };
	virtual note* getAnother() { return n2; };
	void virtDraw();
	note* selfCopy();
	void setAnoTrack(int track) { 
		this->ano_track = track; 
		n2=new note(getEngine(), m_iCurrentScreenX, m_iCurrentScreenY+ano_track * NOTE_SIZE,
			index, m_iDrawWidth, m_iDrawHeight, false, ano_track, m_pTileManager);
	}
	int getAnoTrack() { return ano_track; };

private:
	//void drawInitial(int X, int Y, int FX, int FY, int track);
	note* n1;
	note* n2;
	int ano_track;
};
#pragma once
#include "..\header.h"
#include "../Configuration.h"
#include <queue>
#include "..\BaseEngine.h"
#include <fstream>
#include <string>
#include <iostream>
#include "../notes/note.h"
#include "../notes/DoubleNote.h"
#include "../notes/LongNote.h"

using namespace std;

class Script
{
public:
	vector<int> Type;
	vector<int> Appear;
	vector<int> Len;
	vector<int> track;
	vector<note*> NoteSet;

	int size;
	string scriptName;

	Script(string name, vector<queue<note*>> t) {
		this->scriptName = name;
		this->tracks = t;
		loadScript();
	}
	void loadScript();
	void buildNoteSet(BaseEngine* engine, TileManager* tile);
	queue<note*> Script::getScriptStream() { 
		queue<note*> stream;
		for (int i = 0; i < size; i++) {
			stream.push(NoteSet[i]->selfCopy());
		}
		return stream; 
	}
	void saveScript(int noteId);

private:
	vector<string> split(const string& str, const string& delim);
	vector<queue<note*>> tracks;
};


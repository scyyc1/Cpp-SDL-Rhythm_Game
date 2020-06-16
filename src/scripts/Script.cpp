#include "Script.h"

void Script::saveScript(int noteId)
{
	ofstream outFile("./scripts/backup.txt");
	for (int i=noteId; i < size; i++) {
		switch (Type[i]) {
		case 0:outFile << "Single"; break;
		case 1:outFile << "Double"; break;
		case 2:outFile << "Long"; break;
		}
		outFile << " " << Appear[i];
		outFile << " " << Len[i];
		outFile << " " << track[i];
		if(i!=size-1)outFile << endl;
	}
}

void Script::loadScript()
{
	string path = "./scripts/" + this->scriptName + ".txt";

	string line;
	int lineNum = 0;
	vector<string> temp;

	ifstream in(path);
	if (in)
	{
		while (getline(in, line))
		{
			temp = split(line, " ");
			if (temp[0]._Equal("Single") )
				this->Type.push_back(SINGLE);
			else if(temp[0]._Equal("Double"))
				this->Type.push_back(DOUBLE);
			else
				this->Type.push_back(LONG);
			this->Appear.push_back(stoi(temp[1]));
			this->Len.push_back(stoi(temp[2]));
			this->track.push_back(stoi(temp[3]));
			lineNum++;
		}
	}
	else
	{
		cout << "no such file" << endl;
	}
	this->size = lineNum;
}

void Script::buildNoteSet(BaseEngine* engine, TileManager* tile)
{
	if (size != 0) {
		for (int i = 0; i < size;i++) {
			int t = track[i];

			switch (Type[i]) {
			case 0:NoteSet.push_back(new note(engine, NOTE_START_X, NOTE_START_1_Y + NOTE_SIZE * t,
				i, NOTE_SIZE, NOTE_SIZE, false, t, tile)); break;
			case 1:NoteSet.push_back(new DoubleNote(engine, NOTE_START_X, NOTE_START_1_Y + NOTE_SIZE * t,
				i, NOTE_SIZE, NOTE_SIZE, false, t, tile)); break;
			case 2:NoteSet.push_back(new LongNote(engine, NOTE_START_X, NOTE_START_1_Y + NOTE_SIZE * t,
				i, NOTE_SIZE, NOTE_SIZE, false, t, tile, Len[i])); break;
			}
		}
	}
}

vector<string> Script::split(const string& str, const string& delim)
{
	vector<string> res;
	if ("" == str) return res;

	char* strs = new char[str.length() + 1];
	strcpy(strs, str.c_str());

	char* d = new char[delim.length() + 1];
	strcpy(d, delim.c_str());

	char* p = strtok(strs, d);
	while (p) {
		string s = p;
		res.push_back(s); 
		p = strtok(NULL, d);
	}

	return res;
}

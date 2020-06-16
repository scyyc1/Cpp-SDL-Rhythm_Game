#include "Ranking.h"

void Ranking::save()
{
	ofstream outFile("./Ranking/rank.txt");
	for (int i = 0; i < size; i++) {
		outFile << name[i] << " " << score[i];
		if (i != size - 1)
			outFile << endl;
	}
}

void Ranking::load()
{
	string path = "./Ranking/rank.txt";
	string line;
	int lineNum = 0;
	vector<string> temp;

	ifstream in(path);
	if (in)
	{
		while (getline(in, line))
		{
			temp = split(line, " ");
			name.push_back(temp[0]);
			score.push_back(stoi(temp[1]));
			lineNum++;
		}
	}
	else
	{
		cout << "no such file" << endl;
	}
	this->size = lineNum;
}

bool Ranking::addToRank(string n, int s)
{
	if (this->size == 0) {
		name.push_back(n);
		score.push_back(s);
		size++;
		return true;
	}else if (this->size == RANK_SIZE) {
		for (int i = 0; i < size; i++) {
			if (s > score[i]) {
				score[i] = s;
				name[i] = n;
				return true;
			}
		}
	}
	else {
		for (int i = 0; i < size; i++) {
			if (s > score[i]) {
				score[i] = s;
				name[i] = n;
				return true;
			}
			if (i == size - 1) {
				name.push_back(n);
				score.push_back(s);
				size++;
				return true;
			}
		}
	}
	return false;
}

vector<string> Ranking::split(const string& str, const string& delim)
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
#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "../Configuration.h"
using namespace std;
class Ranking
{
public:
	Ranking() {
		this->size=0;
		load();
	}
	~Ranking() {};
	vector<string> name;
	vector<int> score;
	int size;
	void save();
	void load();
	bool addToRank(string n, int s);

private:
	vector<string> split(const string& str, const string& delim);
};


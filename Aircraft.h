#pragma once
#include <string>

using namespace std;

class Aircraft
{
protected:
	string name;
	int N;
	char **place;
public:
	Aircraft();
	Aircraft(ifstream &fin);
	Aircraft(const Aircraft &);
	Aircraft& operator=(const Aircraft&);
	string getName();
	int getN();
	char ** getPlace();
	void info();
	void writeFile(ofstream &fout);
	~Aircraft();
};
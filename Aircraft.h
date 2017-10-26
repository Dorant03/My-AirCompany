#pragma once
#include <string>

using namespace std;

class Aircraft
{
protected:
	string name;
	int N;
	string *place;
public:
	Aircraft();
	Aircraft(int);
	Aircraft(ifstream &fin);
	
	string getName();
	int getN();
	string * getPlace();
	void info();
	~Aircraft();
};

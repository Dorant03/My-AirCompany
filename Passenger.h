#pragma once
#include <string>

using namespace std;

class Passenger
{
protected:
	char name[15];
	char surname[15];
	int year;
	char place[15];
public:
	Passenger();
	Passenger(int);
	Passenger(ifstream &fin);
	Passenger(const Passenger &);
	Passenger& operator=(const Passenger&);
	char * getName();
	char * getSurname();
	int getYear();
	char * getPlace();
	void del();
	void info();
	void writeFile(ofstream &fout);
	~Passenger();
};
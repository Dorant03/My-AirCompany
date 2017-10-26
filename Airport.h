#pragma once
#include <string>

using namespace std;

class Airport
{
protected:
	string name;
	string city;
	string country;
public:
	Airport();
	Airport(int);
	Airport(ifstream &fin);
	Airport(const Airport &);
	Airport& operator=(const Airport&);
	string getName();
	string getCity();
	string getCountry();
	void info();
	~Airport();
};

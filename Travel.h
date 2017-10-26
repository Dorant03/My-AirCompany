#pragma once
#include <string>
#include "Airport.h"
#include "Aircraft.h"
#include "Passenger.h"

using namespace std;

class Travel
{
protected:
	Airport port_start;
	Airport port_end;
	string time_start;
	string time_end;
	Aircraft craft_name;
	Passenger *array_passenger;
	int number_passenger;
public:
	Travel();
	Travel(int);
	Travel(ifstream &fin);
	Travel(const Travel &);
	Travel & operator=(const Travel &ob);
	Airport  getPortStart();
	Airport  getPortEnd();
	Aircraft  getCraftName();
	Passenger * getPassenger();
	int getNumberPassenger();
	void info();
	~Travel();
};

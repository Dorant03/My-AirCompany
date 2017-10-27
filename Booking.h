#pragma once
#include <string>
#include "Travel.h"

using namespace std;

class Booking
{
protected:
	ofstream profit;
	int money;
public:
	Booking();
	void ADD();
	void SUB();
	~Booking();
};